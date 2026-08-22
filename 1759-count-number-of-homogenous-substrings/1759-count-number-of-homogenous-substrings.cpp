class Solution {
public:
    int countHomogenous(string s) {
        const long long MOD = 1e9 + 7;
        long long ans = 0;
        long long len = 1;

        for (int i = 1; i <= s.size(); i++) {
            if (i < s.size() && s[i] == s[i - 1]) {
                len++;
            } else {
                ans = (ans + len * (len + 1) / 2) % MOD;
                len = 1;
            }
        }

        return ans;
    }
};