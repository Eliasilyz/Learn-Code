class Solution {
public:
    vector<string> generate(string s) {
        vector<string> res;

        if (s.size() == 1 || s[0] != '0')
            res.push_back(s);

        for (int i = 1; i < s.size(); i++) {
            string left = s.substr(0, i);
            string right = s.substr(i);

            if (left.size() > 1 && left[0] == '0')
                continue;

            if (right.back() == '0')
                continue;

            res.push_back(left + "." + right);
        }

        return res;
    }

    vector<string> ambiguousCoordinates(string s) {
        vector<string> ans;

        string digits = s.substr(1, s.size() - 2);

        for (int i = 1; i < digits.size(); i++) {
            string x = digits.substr(0, i);
            string y = digits.substr(i);

            vector<string> xs = generate(x);
            vector<string> ys = generate(y);

            for (string &a : xs) {
                for (string &b : ys) {
                    ans.push_back("(" + a + ", " + b + ")");
                }
            }
        }

        return ans;
    }
};