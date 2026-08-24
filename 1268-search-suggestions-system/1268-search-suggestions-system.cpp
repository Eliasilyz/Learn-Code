class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        sort(products.begin(), products.end());
        map<string, vector<string> > m;
        for(auto i : products) {
            for(int j = 1; j <= i.size(); j++) {
                m[i.substr(0, j)].push_back(i);
            }
        }
        
        vector<vector<string> > ans;
        for(int i = 1; i <= searchWord.size(); i++) {
            vector<string> res;
            for(auto j : m[searchWord.substr(0, i)]) {
                res.push_back(j);
                if(res.size() == 3) {
                    break;
                }
            }
            ans.push_back(res);
        }
        return ans;
        
    }
};