class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        for (int pivot = n - 1; pivot >= 0; pivot--) {
            int freq[26] = {};
            for (char c : s)
                freq[c - 'a']++;

            bool possible = true;

            // Match prefix dengan target
            for (int i = 0; i < pivot; i++) {
                int c = target[i] - 'a';

                if (freq[c] == 0) {
                    possible = false;
                    break;
                }

                freq[c]--;
            }

            if (!possible)
                continue;

            // Cari karakter terkecil yang > target[pivot]
            int targetChar = target[pivot] - 'a';
            int bigger = -1;

            for (int c = targetChar + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    bigger = c;
                    break;
                }
            }

            if (bigger == -1)
                continue;

            string ans = target.substr(0, pivot);
            ans += char('a' + bigger);
            freq[bigger]--;

            // Susun sisa karakter sekecil mungkin
            for (int c = 0; c < 26; c++) {
                while (freq[c] > 0) {
                    ans += char('a' + c);
                    freq[c]--;
                }
            }

            return ans;
        }

        return "";
    }
};