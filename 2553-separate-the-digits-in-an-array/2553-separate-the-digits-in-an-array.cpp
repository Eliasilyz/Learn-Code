class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto i:nums){
            for(auto k:to_string(i)){
                ans.push_back(k-'0');
            }
        }
        return ans;
    }
};