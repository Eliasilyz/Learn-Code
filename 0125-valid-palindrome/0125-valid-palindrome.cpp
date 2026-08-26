class Solution {
public:
    bool isPalindrome(string s) {
        string prev = "";
        for(auto i : s){
            if(isalnum(i)){
                prev.push_back(tolower(i));
            }
        }
        cout<<prev<<endl;
        for(int i=0;i<prev.length()/2;i++){
            if(prev[i] != prev[prev.length() - i - 1]){
                return false;
            }
        }
        return true;
    }
};