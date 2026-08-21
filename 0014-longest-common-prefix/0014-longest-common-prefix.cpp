class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int _minlen = INT_MAX;
        for(auto val:strs){
            if(_minlen > val.length()){
                _minlen = val.length();
            }
        }
        string s= "";
        for(int i=0;i<_minlen;i++){
            int flag = 0;
            for(int j=1;j<strs.size();j++){
                if(strs[0][i] != strs[j][i]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                s += strs[0][i];
            }
            else{
                break;
            }
        }
        return s;
    }
};