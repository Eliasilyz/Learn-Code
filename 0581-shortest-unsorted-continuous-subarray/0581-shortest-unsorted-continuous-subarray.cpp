class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> arr =nums;
        sort(nums.begin(),nums.end());
        int len = nums.size();
        int i =0,j=len-1;
        while(i<len){
            if(nums[i]!=arr[i]){
                break;
            }
            i++;
        }
        while(j>=0){
            if(nums[j]!=arr[j]){
                break;
            }
            j--;
        }
        return (i>=j) ? 0:j-i+1;
    }
};