class Solution {
public:
    int hamming(string &a, string &b) {
        if (a.size() != b.size()) return -1;

        int cnt = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) cnt++;
        }

        return cnt;
    }

    vector<string> getWordsInLongestSubsequence(
        vector<string>& words,
        vector<int>& groups
    ) {
        int n = words.size();

        vector<int> dp(n, 1);
        vector<int> parent(n, -1);

        int best = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] == groups[j])
                    continue;

                if (hamming(words[i], words[j]) != 1)
                    continue;

                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }

            if (dp[i] > dp[best])
                best = i;
        }

        vector<string> ans;

        while (best != -1) {
            ans.push_back(words[best]);
            best = parent[best];
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};