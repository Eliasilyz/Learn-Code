class Solution {
public:
    using Poly = map<vector<string>, int>;

    string s;
    int pos = 0;
    unordered_map<string, int> values;

    void skipSpaces() {
        while (pos < s.size() && s[pos] == ' ')
            pos++;
    }

    Poly add(Poly a, const Poly& b, int sign = 1) {
        for (auto &[vars, coef] : b)
            a[vars] += coef * sign;

        return a;
    }

    Poly multiply(const Poly& a, const Poly& b) {
        Poly res;

        for (auto &[v1, c1] : a) {
            for (auto &[v2, c2] : b) {
                vector<string> vars = v1;

                vars.insert(
                    vars.end(),
                    v2.begin(),
                    v2.end()
                );

                sort(vars.begin(), vars.end());

                res[vars] += c1 * c2;
            }
        }

        return res;
    }

    Poly parseExpression() {
        Poly res = parseTerm();

        while (true) {
            skipSpaces();

            if (pos >= s.size() || s[pos] == ')')
                break;

            char op = s[pos++];

            Poly term = parseTerm();

            if (op == '+')
                res = add(res, term);
            else
                res = add(res, term, -1);
        }

        return res;
    }

    Poly parseTerm() {
        Poly res = parseFactor();

        while (true) {
            skipSpaces();

            if (pos >= s.size() || s[pos] != '*')
                break;

            pos++;

            Poly factor = parseFactor();
            res = multiply(res, factor);
        }

        return res;
    }

    Poly parseFactor() {
        skipSpaces();

        if (s[pos] == '(') {
            pos++;

            Poly res = parseExpression();

            skipSpaces();
            pos++; // ')'

            return res;
        }

        int start = pos;

        while (
            pos < s.size() &&
            isalnum(s[pos])
        ) {
            pos++;
        }

        string token = s.substr(start, pos - start);

        // Number
        if (isdigit(token[0])) {
            return {{{}, stoi(token)}};
        }

        // Variable sudah dievaluasi
        if (values.count(token)) {
            return {{{}, values[token]}};
        }

        // Variable bebas
        return {{{token}, 1}};
    }

    vector<string> basicCalculatorIV(
        string expression,
        vector<string>& evalvars,
        vector<int>& evalints
    ) {
        s = expression;
        pos = 0;
        values.clear();

        for (int i = 0; i < evalvars.size(); i++)
            values[evalvars[i]] = evalints[i];

        Poly poly = parseExpression();

        vector<pair<vector<string>, int>> terms;

        for (auto &[vars, coef] : poly) {
            if (coef != 0)
                terms.push_back({vars, coef});
        }

        sort(
            terms.begin(),
            terms.end(),
            [](const auto& a, const auto& b) {
                if (a.first.size() != b.first.size())
                    return a.first.size() > b.first.size();

                return a.first < b.first;
            }
        );

        vector<string> ans;

        for (auto &[vars, coef] : terms) {
            string term = to_string(coef);

            for (auto &var : vars)
                term += "*" + var;

            ans.push_back(term);
        }

        return ans;
    }
};