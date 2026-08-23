class Solution {
public:
    string reverseWords(string s) {
        string ans = "", temp="";
        for(auto i : s){
            if(i == ' '){
                reverse(temp.begin(), temp.end());
                ans += temp;
                ans.push_back(' ');
                temp = "";
            }else{
                temp.push_back(i);
            }
        }
        reverse(temp.begin(), temp.end());
        ans += temp;
        return ans;
    }
};