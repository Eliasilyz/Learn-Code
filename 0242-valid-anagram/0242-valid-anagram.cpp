class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        int arr1[26], arr2[26];
        memset(arr1, 0 , sizeof arr1);
        memset(arr2, 0 , sizeof arr2);
        for(auto i : s){
            arr1[(i-'a')]++;
        }
        for(auto i : t){
            arr2[(i-'a')]++;
        }
        for(int i = 0; i < 26;i++){
            if(arr1[i] != arr2[i]){
                return false;
            }
        }
        return true;
    }
};