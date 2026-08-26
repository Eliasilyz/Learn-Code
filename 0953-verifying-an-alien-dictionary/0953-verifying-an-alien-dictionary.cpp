class Solution {
public:
     map<char, int> m;
    bool compare(string s, string t) {
        if(s == t) {
            return true;
        }
        int i = 0;
       for(i = 0; i < min(s.size(), t.size()); i++) {
           if(m[s[i]] < m[t[i]]) {
               return true;
           }
           else if(m[s[i]] > m[t[i]]) {
               return false;
           }
       }
       return i == s.size();
    }
    bool isAlienSorted(vector<string>& words, string order) {
       
        int cnt = 0;
        for(auto i : order) {
            m[i] = cnt++;
        }
        for(int i  = 1; i < words.size(); i++) {
            if(!compare(words[i - 1], words[i])) {
                return false;
            }
        }
        return true;

    }
};