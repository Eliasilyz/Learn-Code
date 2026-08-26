map<int, map<int, map<int, int>>> dp;
class Solution {
public:
    int helper(int  a, int b, int c){
        int d = 0, e = 0;
        if(dp[a][b].count(c) > 0)return dp[a][b][c];
        if(a > 0)
            d = 1 + helper(a - 1, b + 1, c);
        if(b >= c){
            e = helper(a + 1, b - c, c + 1);
        }
        return dp[a][b][c] = max(d, e);
    }   
    int maxBottlesDrunk(int numBottles, int numExchange) {
        dp.clear();
        return helper(numBottles, 0, numExchange);
    }
};