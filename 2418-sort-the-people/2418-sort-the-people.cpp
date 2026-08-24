class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> ans;
        for(int i = 0; i < names.size(); i++){
            ans.push_back({heights[i], names[i]});
        }
        sort(ans.begin(), ans.end());
        vector<string> arr;
        for(auto i : ans){
            arr.push_back(i.second);
        }
        reverse(arr.begin(), arr.end());
        return arr;
    }
};