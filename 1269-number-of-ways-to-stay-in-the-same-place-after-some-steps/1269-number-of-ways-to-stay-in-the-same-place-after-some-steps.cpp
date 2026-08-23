int dp[505][505];
const int MOD = 1e9 + 7;
class Solution {
public:
    int helper(int steps, int diff, int n){
        if(diff < 0 || diff >= n)return 0;
        if(steps == 0) return (diff == 0);
        if(dp[steps][diff] != -1)return dp[steps][diff];
        int ans = 0;
        ans += helper(steps - 1 ,diff + 1, n);
        ans%=MOD;
        ans += helper(steps - 1, diff, n);
        ans%=MOD;
        ans += helper(steps - 1, diff - 1, n);
        ans%=MOD;
        return dp[steps][diff] = ans%MOD;
    }
    int numWays(int steps, int n) {
        memset(dp, -1, sizeof dp);
        return helper(steps, 0, n)%MOD;
    }
};