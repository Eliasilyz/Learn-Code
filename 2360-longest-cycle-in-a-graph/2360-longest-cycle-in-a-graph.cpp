class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> state(n, 0);
        vector<int> depth(n, 0);

        int ans = -1;

        for (int start = 0; start < n; start++) {
            if (state[start] != 0)
                continue;

            int cur = start;
            int d = 0;

            while (cur != -1 && state[cur] == 0) {
                state[cur] = 1;
                depth[cur] = d++;
                cur = edges[cur];
            }

            if (cur != -1 && state[cur] == 1) {
                ans = max(ans, d - depth[cur]);
            }

            // Tandai path ini selesai
            cur = start;
            while (cur != -1 && state[cur] == 1) {
                state[cur] = 2;
                cur = edges[cur];
            }
        }

        return ans;
    }
};