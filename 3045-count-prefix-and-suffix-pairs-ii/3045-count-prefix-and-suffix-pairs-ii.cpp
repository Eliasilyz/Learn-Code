class Solution {
public:
    struct Node {
        int next[26];
        int cnt;

        Node() {
            fill(next, next + 26, -1);
            cnt = 0;
        }
    };

    long long countPrefixSuffixPairs(vector<string>& words) {
        vector<Node> trie(1);
        long long ans = 0;

        for (string &s : words) {
            int n = s.size();

            // KMP prefix function
            vector<int> pi(n);

            for (int i = 1; i < n; i++) {
                int j = pi[i - 1];

                while (j > 0 && s[i] != s[j])
                    j = pi[j - 1];

                if (s[i] == s[j])
                    j++;

                pi[i] = j;
            }

            // Semua panjang prefix yang juga suffix
            vector<bool> border(n + 1, false);

            int len = n;
            while (len > 0) {
                border[len] = true;
                len = pi[len - 1];
            }

            // Cari prefix yang merupakan suffix
            int node = 0;

            for (int i = 0; i < n; i++) {
                int c = s[i] - 'a';

                if (trie[node].next[c] == -1) {
                    trie[node].next[c] = trie.size();
                    trie.emplace_back();
                }

                node = trie[node].next[c];

                int len = i + 1;

                if (border[len]) {
                    ans += trie[node].cnt;
                }
            }

            // Hanya increment node akhir sebuah WORD
            trie[node].cnt++;
        }

        return ans;
    }
};