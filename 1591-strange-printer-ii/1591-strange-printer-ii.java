class Solution {
    public boolean isPrintable(int[][] targetGrid) {
        int LEFT = 0, RIGHT = 1, TOP = 2, BOTTOM = 3;
        Map<Integer, int[]> coordinates = new HashMap<>();  // {left, right, top, bottom}
        Map<Integer, Set<Integer>> adj = new HashMap<>();   // adjacency list for colors
        Map<Integer, Integer> indegree = new HashMap<>();
        Queue<Integer> q = new LinkedList<>();
        
        int m = targetGrid.length, n = targetGrid[0].length;
        
        // Finding the stretch of each color
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int color = targetGrid[i][j];
                if (coordinates.containsKey(color)) {
                    int[] coordinate = coordinates.get(color);
                    coordinate[LEFT] = Math.min(coordinate[LEFT], j);
                    coordinate[RIGHT] = Math.max(coordinate[RIGHT], j);
                    coordinate[TOP] = Math.min(coordinate[TOP], i);
                    coordinate[BOTTOM] = Math.max(coordinate[BOTTOM], i);
                } else {
                    coordinates.put(color, new int[]{j, j, i, i});
                    adj.put(color, new HashSet<>());
                }
            }
        }
        
        // Building an adjacency list
        for (Map.Entry<Integer, int[]> entry : coordinates.entrySet()) {
            Integer currentColor = entry.getKey();
            int[] coordinate = entry.getValue();
            for (int i = coordinate[TOP]; i <= coordinate[BOTTOM]; ++i) {
                for (int j = coordinate[LEFT]; j <= coordinate[RIGHT]; ++j) {
                    int color = targetGrid[i][j];
                    if (currentColor != color) {
                        adj.get(currentColor).add(color);
                    }
                }
            }
            indegree.put(currentColor, 0);
        }
        
        // Update indegrees of each color
        for (Set<Integer> entry : adj.values()) {
            for (int color : entry) {
                indegree.put(color, indegree.get(color) + 1);
            }
        }
        
        // Add nodes with zero indegree to the queue
        for (Map.Entry<Integer, Integer> entry : indegree.entrySet()) {
            if (entry.getValue() == 0)
                q.add(entry.getKey());
        }
        
		// Kahn's algorithm in action
        int size = 0;
        while (!q.isEmpty()) {
            int currentColor = q.remove();
            size++;
            for (int color : adj.get(currentColor)) {
                indegree.put(color, indegree.get(color) - 1);
                if (indegree.get(color) == 0)
                    q.add(color);
            }
        }
        
		// If there was a cycle, all the nodes wouldn't have been processed, 
		// since there is no valid topological order.
        return size == adj.size();
    }
}