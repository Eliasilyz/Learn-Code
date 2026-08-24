class Solution {
public:
    int find(int e, int f, vector<vector<int> > &dp){
        if(f == 0 || f == 1) return dp[e][f] = f;
        if(e == 1) return dp[e][f] = f;
        int ans = 1000000;
        if(dp[e][f] != -1) return dp[e][f];
        int l = 1;
        int r = f;
        while(l <= r){
            int mid = (l+r)/2;
            int left = find(e-1, mid-1, dp);
            int right = find(e, f-mid, dp);
            int temp = 1 + max(left, right);
            if(left < right){
                l = mid+1;
            }
            else r = mid-1;
            
            ans = min(temp, ans);
        }
        return dp[e][f] = ans;
        
        
    }

    
    int superEggDrop(int e, int f) {
        vector<vector<int> > dp(e+1, vector<int>(f+1, -1));
        // memset(dp, -1, sizeof dp);
        return find(e, f, dp);
    }
};