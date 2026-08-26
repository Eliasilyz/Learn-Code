typedef long long int ll;
const int MOD = 1e9 + 7;
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        vector<ll> pre(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 1; i < n; i++){
            pre[i] += pre[i - 1];
        } 
        ll ans = 0;
        for(int i = 0; i < n; i++){
            if((pre[n - 1] - pre[i]) < 2 * pre[i])break;
            int start = lower_bound(pre.begin() + i + 1, pre.end() - 1, 2 * pre[i]) - pre.begin();
            int end = upper_bound(pre.begin() + i + 1, pre.end() - 1, (pre[n - 1] + pre[i])/2) - pre.begin();
            if(start <= end){
                ans = (ans + (end - start))%MOD;
            }
            // printf("%d %d %d\n", i, start, end);
        }
        return ans%MOD;
    }
};