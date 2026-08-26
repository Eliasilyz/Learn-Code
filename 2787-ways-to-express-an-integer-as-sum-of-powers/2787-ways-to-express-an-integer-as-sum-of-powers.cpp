typedef long long int ll;
const int MOD = 1e9 + 7;
ll dp[350][350];
class Solution {
public:
    ll helper(ll n, ll x, ll ind)
    {
        if (n == 0)
            return 1;
        if (n < 0 || pow(ind, x) > n)
            return 0;
        if(dp[n][ind] != -1)return dp[n][ind];
        ll ans = 0;
        ll tk = 0, nt = 0;
        tk = helper(n - pow(ind, x), x, ind + 1)%MOD;
        nt = helper(n, x, ind + 1)%MOD;
        return dp[n][ind] = (tk + nt)%MOD;
    }
    int numberOfWays(int n, int x)
    {
        memset(dp, -1, sizeof dp);
        return helper(n, x, 1)%MOD;
    }
};