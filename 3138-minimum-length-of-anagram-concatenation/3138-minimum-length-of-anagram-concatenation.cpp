class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();

        for (int len = 1; len <= n; len++) {
            if (n % len != 0) continue;

            int base[26] = {};

            for (int i = 0; i < len; i++)
                base[s[i] - 'a']++;

            bool ok = true;

            for (int start = len; start < n && ok; start += len) {
                int freq[26] = {};

                for (int i = start; i < start + len; i++)
                    freq[s[i] - 'a']++;

                for (int j = 0; j < 26; j++) {
                    if (freq[j] != base[j]) {
                        ok = false;
                        break;
                    }
                }
            }

            if (ok)
                return len;
        }

        return n;
    }
};