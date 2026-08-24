class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])
        
        minHeap = [[grid[0][0], 0, 0]] # maxHeight, r, c
        visit = set([0, 0])
        
        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        
        while minHeap:
            maxHeight, r, c = heappop(minHeap)
            if (r, c) in visit:
                continue
            if r == ROWS - 1 and c == COLS - 1:
                return maxHeight
            visit.add((r, c))
            for dr, dc in directions:
                row, col = r + dr, c + dc 
                if row < 0 or col < 0 or row == ROWS or col == COLS or (row, col) in visit:
                    continue
                heappush(minHeap, [max(maxHeight, grid[row][col]), row, col])
                