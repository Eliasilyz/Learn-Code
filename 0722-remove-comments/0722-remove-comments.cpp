class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        string cur;
        bool inBlock = false;

        for (string &line : source) {
            int i = 0;

            while (i < line.size()) {
                if (!inBlock) {
                    // Mulai block comment
                    if (i + 1 < line.size() &&
                        line[i] == '/' && line[i + 1] == '*') {
                        inBlock = true;
                        i += 2;
                    }
                    // Line comment
                    else if (i + 1 < line.size() &&
                             line[i] == '/' && line[i + 1] == '/') {
                        break;
                    }
                    // Normal character
                    else {
                        cur += line[i];
                        i++;
                    }
                } else {
                    // Akhir block comment
                    if (i + 1 < line.size() &&
                        line[i] == '*' && line[i + 1] == '/') {
                        inBlock = false;
                        i += 2;
                    } else {
                        i++;
                    }
                }
            }

            // Kalau tidak sedang block comment,
            // berarti newline boleh dibuat.
            if (!inBlock && !cur.empty()) {
                ans.push_back(cur);
                cur.clear();
            }
        }

        return ans;
    }
};