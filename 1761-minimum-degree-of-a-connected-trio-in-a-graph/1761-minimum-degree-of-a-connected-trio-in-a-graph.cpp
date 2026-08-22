class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));
        vector<int> degree(n + 1, 0);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            graph[u][v] = true;
            graph[v][u] = true;

            degree[u]++;
            degree[v]++;
        }

        int ans = INT_MAX;

        for (int a = 1; a <= n; a++) {
            for (int b = a + 1; b <= n; b++) {
                if (!graph[a][b]) continue;

                for (int c = b + 1; c <= n; c++) {
                    if (graph[a][c] && graph[b][c]) {
                        int trioDegree =
                            degree[a] +
                            degree[b] +
                            degree[c] -
                            6;

                        ans = min(ans, trioDegree);
                    }
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};