class Solution {
public:
    int cnt = -1;
    void helper(vector<int> &nums, int k, int ind, vector<int> &ans, unordered_map<int, int> &m){
        if(ind == nums.size()){
            cnt++;
            return;
        }
        helper(nums, k, ind + 1, ans , m);
        if(m[nums[ind] + k] == 0 && m[nums[ind] - k] == 0){
            m[nums[ind]]++;
            ans.push_back(nums[ind]);
            helper(nums, k, ind + 1, ans, m);
            ans.pop_back();
            m[nums[ind]]--;
        }        
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        cnt = 0;
        unordered_map<int, int> m;
        vector<int> temp;
        helper(nums, k, 0, temp, m);
        return cnt - 1;
    }
};