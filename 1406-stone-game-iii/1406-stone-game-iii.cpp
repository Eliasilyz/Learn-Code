int dp[50005][2];
class Solution {
public:
    int helper(vector<int> &arr, int ind, bool alice){
        if(ind == arr.size())return 0;
        if(dp[ind][alice] != -1)return dp[ind][alice];
        int ans = alice?-1e9:1e9;
        int sum = 0;
        for(int i = 0; i < 3 && ind + i < arr.size(); i++){
            sum += arr[ind + i];
            if(alice){
                ans = max(ans, sum + helper(arr, ind + i + 1, !alice));
            }else{
                ans = min(ans, -sum + helper(arr, ind + i + 1, !alice));
            }
        }
        return dp[ind][alice] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp, -1, sizeof dp);
        int ans = helper(stoneValue, 0, true);
        if(ans > 0)return "Alice";
        else if(ans == 0)return "Tie";
        else return "Bob";
    }
};