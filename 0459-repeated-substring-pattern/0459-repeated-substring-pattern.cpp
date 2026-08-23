class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.length() == 1)return false;
        string temp = "";
        for(int i = 1; i < s.length();i++){
            temp.push_back(s[i - 1]);
            if(s.length()%i == 0){
                string temp2 = "";
                for(int j = 0; j < s.length()/i;j++){
                    temp2 += temp;
                }
                if(temp2 == s)return true;
            }
        }
        return false;
    }
};