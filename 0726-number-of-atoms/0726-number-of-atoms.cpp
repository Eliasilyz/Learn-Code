class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        int i = 0;

        stack<map<string, int>> st;
        st.push({});

        while (i < n) {
            if (formula[i] == '(') {
                st.push({});
                i++;
            }
            else if (formula[i] == ')') {
                i++;

                int multiplier = 0;

                while (i < n && isdigit(formula[i])) {
                    multiplier = multiplier * 10 + (formula[i] - '0');
                    i++;
                }

                if (multiplier == 0)
                    multiplier = 1;

                auto current = st.top();
                st.pop();

                for (auto& [atom, count] : current) {
                    st.top()[atom] += count * multiplier;
                }
            }
            else {
                string atom;
                atom += formula[i++];

                while (i < n && islower(formula[i])) {
                    atom += formula[i++];
                }

                int count = 0;

                while (i < n && isdigit(formula[i])) {
                    count = count * 10 + (formula[i] - '0');
                    i++;
                }

                if (count == 0)
                    count = 1;

                st.top()[atom] += count;
            }
        }

        string result;

        for (auto& [atom, count] : st.top()) {
            result += atom;

            if (count > 1) {
                result += to_string(count);
            }
        }

        return result;
    }
};