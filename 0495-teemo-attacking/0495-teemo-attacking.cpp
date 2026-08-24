class Solution {
public:
    int findPoisonedDuration(vector<int>& v, int duration) {
        vector<vector<int>> arr;
        for(auto i : v)arr.push_back({i, i + duration - 1});
        sort(arr.begin(), arr.end());
        vector<int> curr = arr[0];
        vector<vector<int>> ans;
        for(int i = 1; i < arr.size();i++){
            if(curr[1] >= arr[i][0]){
                curr[1] = max(arr[i][1], curr[1]);
            }else{
                ans.push_back(curr);
                curr = arr[i];
            }
        }
        ans.push_back(curr);
        int res = 0;
        for(auto i : ans){
            res += (i[1] - i[0] + 1);
        }
        return res;
    }
};