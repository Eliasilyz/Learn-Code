class Solution {
private:
    struct StringStruct {
        int i, j, len;
    } dp[1001][1001];
    void buildString(string &build, string &str1, string &str2, int i, int j) {
        if (i == 0 && j == 0) return;
        else if (i == 0) { build += string(str2, 0, j); return; } 
        else if (j == 0) { build += string(str1, 0, i); return; }
        else buildString(build, str1, str2, i - dp[i][j].i, j - dp[i][j].j);
        if (dp[i][j].i == 0) { build += str2[j - 1]; return; }
        if (dp[i][j].j == 0) { build += str1[i - 1]; return; }
        if (str1[i - 1] == str2[j - 1])
            build += str1[i - 1];
        else {
            build += str1[i - 1];
            build += str2[j - 1];
        }
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        for (int i = 0; i <= str1.size(); ++i)
            for (int j = 0; j <= str2.size(); ++j) {
                if (i == 0 && j == 0)
                    dp[i][j].len = dp[i][j].i = dp[i][j].j = 0;
                else if (i == 0) 
                    dp[i][j].len = j;
                else if (j == 0) 
                    dp[i][j].len = i;
                else { // (i > 0 && j > 0) 
                    dp[i][j].i = dp[i][j].j = 1;
                    dp[i][j].len = dp[i - 1][j - 1].len + (str1[i - 1] == str2[j - 1] ? 1 : 2);
                    if (dp[i - 1][j].len + 1 < dp[i][j].len) {
                        dp[i][j].j = 0;
                        dp[i][j].len = dp[i - 1][j].len + 1;
                    }
                    if (dp[i][j - 1].len + 1 < dp[i][j].len) {
                        dp[i][j].i = 0;
                        dp[i][j].len = dp[i][j - 1].len + 1;
                    }
                }
            }
        string ans = "";
        buildString(ans, str1, str2, str1.size(), str2.size());
        return ans;
    }
};