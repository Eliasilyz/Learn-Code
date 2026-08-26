class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        vector<int> arr;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1)arr.push_back(i);
        }
        if(arr.size() == 0)return 0;
        long long ans = 1, MOD = 1e9 + 7;
        for(int i = 0; i < arr.size() - 1; i++){
            ans = ((ans%MOD) * (arr[i + 1] - arr[i])%MOD)%MOD;
        }
        return ans;
    }
};