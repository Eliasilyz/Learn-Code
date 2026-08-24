class Solution {
public:
    int ans = 0;
    void foo(vector<int> &nums, int target, int n, int sum)
    {
        if (n == 0)
        {
            if (sum == target)
            {
                ans++;
            }
            return ;
        }

        foo(nums, target, n - 1, sum + nums[n - 1]);
        foo(nums, target, n - 1, sum - nums[n - 1]);
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        ans = 0;
        foo(nums, target, nums.size(), 0);
        return ans;
    }
};