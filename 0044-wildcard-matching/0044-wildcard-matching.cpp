class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length(), m = s.length();
        bool dp[n+1][m + 1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for(int i = 1; i <=m;i++){
            dp[0][i] = false;
        }
        for(int i = 1; i <= n;i++){
            if(p[i - 1] == '*'){
                dp[i][0] = true;
            }else{
                break;
            }
        }
        for(int i = 1;i <=n;i++){
            for(int j = 1;j<=m;j++){
                if(p[i - 1] == s[j - 1] || p[i - 1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[i - 1] == '*'){
                    dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
                }else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
        
    }
};