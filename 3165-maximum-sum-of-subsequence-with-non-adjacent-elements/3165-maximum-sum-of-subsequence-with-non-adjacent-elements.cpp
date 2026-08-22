class Solution {
public:
    static const long long NEG = -(1LL << 60);
    
    struct Node {
        long long dp[2][2];

        Node() {
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    dp[i][j] = NEG;
        }
    };

    vector<Node> tree;
    vector<int> nums;

    Node merge(Node &L, Node &R) {
        Node res;

        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
                for (int c = 0; c < 2; c++) {
                    for (int d = 0; d < 2; d++) {

                        // L's right and R's left cannot both be selected
                        if (b && c) continue;

                        res.dp[a][d] = max(
                            res.dp[a][d],
                            L.dp[a][b] + R.dp[c][d]
                        );
                    }
                }
            }
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node].dp[0][0] = 0;
            tree[node].dp[1][1] = nums[l];
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, int val) {
        if (l == r) {
            tree[node] = Node();
            tree[node].dp[0][0] = 0;
            tree[node].dp[1][1] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(node * 2, l, mid, pos, val);
        else
            update(node * 2 + 1, mid + 1, r, pos, val);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    int maximumSumSubsequence(
        vector<int>& nums,
        vector<vector<int>>& queries
    ) {
        this->nums = nums;

        int n = nums.size();
        tree.resize(4 * n + 5);

        build(1, 0, n - 1);

        long long ans = 0;
        const long long MOD = 1000000007;

        for (auto &q : queries) {
            int pos = q[0];
            int val = q[1];

            update(1, 0, n - 1, pos, val);

            long long best = 0;

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    best = max(best, tree[1].dp[i][j]);
                }
            }

            ans = (ans + best) % MOD;
        }

        return ans;
    }
};