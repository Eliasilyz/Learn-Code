class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans(n, 0);
        int i = (n - 1)/2, j = n - 1;
        for(int k = 0; k < n; k++){
            if(k%2 == 0){
                ans[k] = nums[i--];
            }else{
                ans[k] = nums[j--];
            }
        }
        nums = ans;
    }
};