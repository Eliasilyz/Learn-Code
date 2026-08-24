from typing import List


class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        self.parent = [i for i in range(26)]
        for eqs in equations:
            p = eqs[0]
            q = eqs[3]
            operation = eqs[1:3]
            if operation == "==":
                self.union(ord(p) - ord('a'), ord(q) - ord('a'))

        for eqs in equations:
            p = eqs[0]
            q = eqs[3]
            operation = eqs[1:3]
            if operation == "!=":
                if self.connected(ord(p) - ord('a'), ord(q) - ord('a')):
                    return False
        return True

    def union(self, i, j):
        p1 = self.find_parent(i)
        p2 = self.find_parent(j)
        if p1 != p2:
            self.parent[p1] = p2

    def connected(self, i: int, j: int):
        p1 = self.find_parent(i)
        p2 = self.find_parent(j)
        return p1 == p2

    def find_parent(self, i: int):
        if self.parent[i] == i:
            return i
        elif self.parent[i] != i:
            self.parent[i] = self.find_parent(self.parent[i])
        return self.parent[i]


