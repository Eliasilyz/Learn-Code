class Solution:
    def stoneGameVI(self, a: List[int], b: List[int]) -> int:
        comb = []
        for i in range(len(a)):
            comb.append((a[i] + b[i], i))
        
        comb.sort()
        alice = 0
        al = True
        for i in range(len(comb)):
            if al:
                alice += a[comb[-i-1][1]]
            else:
                alice -= b[comb[-i-1][1]]
            al = not al
        return int(alice / abs(alice)) if alice != 0 else alice