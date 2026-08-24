class Solution:
    def scoreOfStudents(self, s: str, answers: List[int]) -> int:

        # dp(i, j) return a dictionary of all possible results for the substring from s[i] to s[j]
        @lru_cache(None)
        def dp(i, j): 
            if i == j:
                return {int(s[i])}

            res = {}
            # op is the index of the operator
            for op in range(i+1, j, 2):
                for a in dp(i, op-1):
                    for b in dp(op+1, j):
                        cur = a * b if s[op] == "*" else a + b
                        if cur <= 1000:
                            res[cur] = 2 # get 2 points for wrong order calculation 

            return res

        # merge two dictionary:
        # 1. dp stores the 2 points answer, which has right arithmetic but wrong order 
        # 2. eval(s) evalutes the correct answer, and assigns 5 points. 
        res = {**dp(0, len(s)-1), **{eval(s) : 5}}

        return sum(res.get(a, 0) for a in answers) 
        

# Time = O(k^3 * 1000^2)
# Enumerating all substrings O(k^2),
# then for each substring,
# there are O(k) ways to break it into two parts,
# then executing the math takes at most 1000^2.

# More precisely,
# size_a = min(1000, size(a)!)
# size_b = min(1000, size(b)!)
# k = 15 - size_a - size_b, where k > 0

# The total complexity is the sum of
# size_a * size_b * k
# which is about 10 millions.
# https://leetcode.com/problems/the-score-of-students-solving-math-expression/solutions/1486296/python-dp-solution-with-complexity-analysis/