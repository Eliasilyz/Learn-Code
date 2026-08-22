class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string half;

        for (int i = 0; i < 26; i++) {
            half += string(freq[i] / 2, 'a' + i);
        }

        string result = half;

        if (s.size() % 2 == 1) {
            for (int i = 0; i < 26; i++) {
                if (freq[i] % 2 == 1) {
                    result += char('a' + i);
                    break;
                }
            }
        }

        reverse(half.begin(), half.end());
        result += half;

        return result;
    }
};