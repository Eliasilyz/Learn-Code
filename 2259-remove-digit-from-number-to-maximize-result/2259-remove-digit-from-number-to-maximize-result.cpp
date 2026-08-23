class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        string ans = "";
        for(int i = n - 1; i >=0;i--){
            if(number[i] == digit){
                string s = number;
                s.erase(s.begin() + i);
                if(ans < s){
                    ans = s;
                }
            }
        }
        return ans;
    }
};