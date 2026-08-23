class Solution {
public:
    int removePalindromeSub(string s) {
        //max no of operations could be 2
        int  i = 0;
        int n = s.length();
        int j = n - 1;
        if(n == 0) {
            return 0;
        }
        
        
        while(i < j) {
            if(s[i++] != s[j--]) {
                return 2;
            }
        }
        return 1;
    }
};