class Solution {
public:

vector<long long> distance(vector<int> &nums)
{
    map<long long, vector<long long>> mp;
    map<long long, vector<long long>> pre;
    int n = nums.size();
    vector<long long> ans(n);
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]].push_back(i);
        pre[nums[i]].push_back(i);
    }
    for (auto &it : pre)
    {
        for (int i = 1; i < it.second.size(); i++)
        {
            it.second[i] += it.second[i - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {  
        int ind1 = lower_bound(mp[nums[i]].begin(), mp[nums[i]].end(), i) - mp[nums[i]].begin();
        long long left = 0;
        long long num = mp[nums[i]][ind1];
        if (ind1 > 0)
        {
            left = ind1 * (num)-pre[nums[i]][ind1 - 1];
        }
        long long right = 0;
        if (ind1 < n - 1)
        {
            right = pre[nums[i]].back() - pre[nums[i]][ind1] - (pre[nums[i]].size() - ind1 - 1) * num;
        }
        ans[i] = left + right;
    }
    return ans;
}
};