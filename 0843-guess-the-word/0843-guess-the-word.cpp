/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int match(const string& a, const string& b) {
        int cnt = 0;

        for (int i = 0; i < 6; i++) {
            if (a[i] == b[i])
                cnt++;
        }

        return cnt;
    }

    void findSecretWord(vector<string>& words, Master& master) {
        vector<string> candidates = words;

        while (!candidates.empty()) {
            string best = candidates[0];
            int bestScore = INT_MAX;

            // Pilih guess yang meminimalkan kandidat terburuk
            for (const string& guess : candidates) {
                int groups[7] = {};

                for (const string& word : candidates) {
                    groups[match(guess, word)]++;
                }

                int worst = 0;

                for (int i = 0; i <= 6; i++)
                    worst = max(worst, groups[i]);

                if (worst < bestScore) {
                    bestScore = worst;
                    best = guess;
                }
            }

            int score = master.guess(best);

            if (score == 6)
                return;

            vector<string> next;

            for (const string& word : candidates) {
                if (match(best, word) == score)
                    next.push_back(word);
            }

            candidates = move(next);
        }
    }
};