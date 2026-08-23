class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        int n = pizza[0].size();

        vector<vector<int>> apples(m + 1, vector<int>(n + 1));

        // suffix sum jumlah apel
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                apples[i][j] =
                    (pizza[i][j] == 'A') +
                    apples[i + 1][j] +
                    apples[i][j + 1] -
                    apples[i + 1][j + 1];
            }
        }

        vector<vector<vector<int>>> dp(
            k,
            vector<vector<int>>(m, vector<int>(n))
        );

        // Base: sisa 1 potong
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                dp[0][i][j] = apples[i][j] > 0;

        for (int cuts = 1; cuts < k; cuts++) {
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {

                    long long ways = 0;

                    // Horizontal
                    for (int nr = r + 1; nr < m; nr++) {
                        if (apples[r][c] - apples[nr][c] > 0)
                            ways = (ways + dp[cuts - 1][nr][c]) % MOD;
                    }

                    // Vertical
                    for (int nc = c + 1; nc < n; nc++) {
                        if (apples[r][c] - apples[r][nc] > 0)
                            ways = (ways + dp[cuts - 1][r][nc]) % MOD;
                    }

                    dp[cuts][r][c] = ways;
                }
            }
        }

        return dp[k - 1][0][0];
    }
};