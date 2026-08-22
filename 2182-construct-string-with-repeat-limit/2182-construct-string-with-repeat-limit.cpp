class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        string ans;

        for (int i = 25; i >= 0; ) {
            if (cnt[i] == 0) {
                i--;
                continue;
            }

            int take = min(cnt[i], repeatLimit);

            ans.append(take, char('a' + i));
            cnt[i] -= take;

            if (cnt[i] == 0)
                continue;

            // Butuh karakter lebih kecil sebagai separator
            int j = i - 1;

            while (j >= 0 && cnt[j] == 0)
                j--;

            if (j < 0)
                break;

            ans.push_back(char('a' + j));
            cnt[j]--;

            // Tetap pakai karakter i setelah separator
        }

        return ans;
    }
};