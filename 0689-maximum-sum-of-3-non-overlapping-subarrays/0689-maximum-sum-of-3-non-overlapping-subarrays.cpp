class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        vector<long long> sum(n - k + 1);

        for (int i = 0; i + k <= n; i++)
            sum[i] = pref[i + k] - pref[i];

        int m = sum.size();

        vector<int> left(m);
        left[0] = 0;

        for (int i = 1; i < m; i++) {
            if (sum[i] > sum[left[i - 1]])
                left[i] = i;
            else
                left[i] = left[i - 1];
        }

        vector<int> right(m);
        right[m - 1] = m - 1;

        for (int i = m - 2; i >= 0; i--) {
            if (sum[i] >= sum[right[i + 1]])
                right[i] = i;
            else
                right[i] = right[i + 1];
        }

        long long best = -1;
        vector<int> ans;

        for (int mid = k; mid <= m - k - 1; mid++) {
            int l = left[mid - k];
            int r = right[mid + k];

            long long total = sum[l] + sum[mid] + sum[r];

            if (total > best) {
                best = total;
                ans = {l, mid, r};
            }
        }

        return ans;
    }
};