class Solution {
public:
    int dp[103][104];

    int find(int i, int j , string s) {
        if(i > j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 1 + find(i + 1, j, s);
        for(int k = i + 1; k <= j; k++) {
            if(s[k] == s[i])
                ans = min(ans, find(i, k - 1, s) + find(k + 1, j, s));
        }
        return dp[i][j] = ans;
    }
    int strangePrinter(string s) {
      memset(dp, -1, sizeof dp);
      return find(0, s.size() - 1, s);
    }
};