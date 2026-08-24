class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<queue<int>> arr(32);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 32;j ++){
                if((nums[i] & (1<<j))){
                    arr[j].push(i);
                }
            }
        }
        vector<int> res;
        for(int i = 0; i < n; i++){
            int ans = i;
            for(int j = 0; j < 32; j++){
                if((nums[i] & (1<<j))){
                    arr[j].pop();
                    
                }else{
                    if(!arr[j].empty()){
                        ans = max(ans, arr[j].front());
                    }
                }
            }
            
            res.push_back(ans - i + 1);
        }
        return res;
    }
};