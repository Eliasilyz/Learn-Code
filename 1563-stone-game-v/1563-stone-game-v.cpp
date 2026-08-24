int dp[505][505];
class Solution {
public:
    int helper(vector<int> &pre, int lo, int hi){
        if(lo >= hi)return 0;
        if(dp[lo][hi] != -1)return dp[lo][hi];
        int ans = -1e9;
        for(int i = lo; i < hi; i++){
            int left = pre[i] - pre[lo - 1];
            int right = pre[hi] - pre[i];
            if(left >= right)
                ans = max(ans, right + helper(pre, i + 1, hi));
            if(left <= right)
                ans = max(ans, left + helper(pre, lo, i));
        }
        return dp[lo][hi] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        memset(dp, -1, sizeof dp);
        vector<int> pre = {0};
        for(auto i : stoneValue)pre.push_back(i);
        for(int i = 1; i < pre.size();  i ++)pre[i] += pre[i - 1];
        return helper(pre, 1, pre.size() - 1);        
    }
};