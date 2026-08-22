class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        // dp[i] = jumlah distinct subsequence non-empty
        // setelah memproses s[0..i-1]
        vector<long long> dp(s.size() + 1, 0);

        // last[c] = dp sebelum karakter c terakhir diproses
        vector<long long> last(26, 0);

        for (int i = 1; i <= s.size(); i++) {
            int c = s[i - 1] - 'a';

            // Semua subsequence lama + subsequence baru
            // dengan menambahkan karakter c
            dp[i] = (2 * dp[i - 1] + 1) % MOD;

            // Buang subsequence yang sebelumnya sudah dibuat
            // saat c muncul terakhir
            dp[i] = (dp[i] - last[c] + MOD) % MOD;

            last[c] = dp[i - 1] + 1;
            last[c] %= MOD;
        }

        return dp[s.size()];
    }
};