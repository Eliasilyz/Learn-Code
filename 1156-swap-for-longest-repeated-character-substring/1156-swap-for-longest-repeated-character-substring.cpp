class Solution {
public:
    int maxRepOpt1(string text) {
        int res = 0, n = text.size();
        unordered_map<char, int> charCnt;
        for (char c : text) ++charCnt[c];
        for (int i = 0; i < n; ++i) {
            char cur = text[i];
            int j = i, cnt = 0, diff = 0;
            while (j < n && (text[j] == cur || diff == 0) && cnt < charCnt[cur]) {
                if (cur != text[j]) {
                    ++diff;
                    i = j - 1;
                }
                ++cnt;
                ++j;
            }
            res = max(res, cnt);
        }
        for (int i = n - 1; i >= 0; --i) {
            char cur = text[i];
            int j = i, cnt = 0, diff = 0;
            while (j >= 0 && (text[j] == cur || diff == 0) && cnt < charCnt[cur]) {
                if (cur != text[j]) {
                    ++diff;
                    i = j + 1;
                }
                ++cnt;
                --j;
            }
            res = max(res, cnt);
        }
        return res;
    }
};