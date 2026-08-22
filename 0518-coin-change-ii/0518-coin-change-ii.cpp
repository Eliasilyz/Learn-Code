class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const long long LIMIT = INT_MAX;

        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                if (dp[i - coin] > LIMIT - dp[i]) {
                    dp[i] = LIMIT;
                } else {
                    dp[i] += dp[i - coin];
                }
            }
        }

        return (int)dp[amount];
    }
};