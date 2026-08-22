class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int j = 0;
        int count = 0;

        unordered_map<int, pair<int, int>> seen;

        int s1Count = 0;

        while (s1Count < n1) {
            for (char c : s1) {
                if (c == s2[j]) {
                    j++;

                    if (j == s2.size()) {
                        j = 0;
                        count++;
                    }
                }
            }

            s1Count++;

            if (j == 0) {
                if (seen.count(j)) {
                    int prevS1 = seen[j].first;
                    int prevCount = seen[j].second;

                    int cycleS1 = s1Count - prevS1;
                    int cycleCount = count - prevCount;

                    int remaining = n1 - s1Count;
                    int cycles = remaining / cycleS1;

                    s1Count += cycles * cycleS1;
                    count += cycles * cycleCount;
                }
                else {
                    seen[j] = {s1Count, count};
                }
            }
        }

        return count / n2;
    }
};