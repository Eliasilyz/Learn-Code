class Solution {
public:
    vector<vector<int>> g;
    vector<int> nums, subXor, tin, tout;
    int timer = 0;
    int total;

    void dfs(int u, int parent) {
        tin[u] = timer++;

        subXor[u] = nums[u];

        for (int v : g[u]) {
            if (v == parent) continue;

            dfs(v, u);
            subXor[u] ^= subXor[v];
        }

        tout[u] = timer;
    }

    bool isAncestor(int a, int b) {
        return tin[a] <= tin[b] && tout[b] <= tout[a];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();

        this->nums = nums;
        g.assign(n, {});
        subXor.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        dfs(0, -1);

        total = subXor[0];

        int ans = INT_MAX;

        // Setiap node selain root mewakili satu edge:
        // edge parent -> node
        for (int a = 1; a < n; a++) {
            for (int b = a + 1; b < n; b++) {

                int x, y, z;

                if (isAncestor(a, b)) {
                    // b berada di dalam subtree a
                    x = subXor[b];
                    y = subXor[a] ^ subXor[b];
                    z = total ^ subXor[a];
                }
                else if (isAncestor(b, a)) {
                    // a berada di dalam subtree b
                    x = subXor[a];
                    y = subXor[b] ^ subXor[a];
                    z = total ^ subXor[b];
                }
                else {
                    // Dua subtree terpisah
                    x = subXor[a];
                    y = subXor[b];
                    z = total ^ subXor[a] ^ subXor[b];
                }

                int mx = max({x, y, z});
                int mn = min({x, y, z});

                ans = min(ans, mx - mn);
            }
        }

        return ans;
    }
};