class Solution {
public:
    void helper(string &s, int ind, unordered_map<string, int> &wordDict, vector<string> &arr, string str){
        if(ind == s.length()){
            str.pop_back();
            arr.push_back(str);
            return;
        }
        string temp = "";
        for(int i = ind; i < s.length(); i ++){
            temp.push_back(s[i]);
            if(wordDict.find(temp) != wordDict.end()){
                string temp2 = str;
                temp2.append(temp + ' ');
                helper(s, i + 1, wordDict, arr, temp2);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> map;
        for(auto i : wordDict){
            map[i]++;
        }
        vector<string> arr;
        string temp = "";
        helper(s, 0, map,arr, temp);
        return arr;
    }
};