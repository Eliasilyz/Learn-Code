class Solution {
public:
    long long appealSum(string s) {
        long long ans = 0, curr =0;
        int n = s.length();
        vector<int> prev(26, -1);
        for(int i = 0; i < n ;i++){
            ans += i - prev[s[i] - 'a'];
            curr += ans;
            prev[s[i] - 'a'] = i;
        }
        return curr;
    }
};