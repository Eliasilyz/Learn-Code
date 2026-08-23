class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N / 2;

        vector<vector<long long>> left(n + 1);
        vector<vector<long long>> right(n + 1);

        for (int mask = 0; mask < (1 << n); mask++) {
            long long sumL = 0, sumR = 0;
            int cnt = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sumL += nums[i];
                    sumR += nums[i + n];
                    cnt++;
                }
            }

            left[cnt].push_back(sumL);
            right[cnt].push_back(sumR);
        }

        for (int cnt = 0; cnt <= n; cnt++) {
            sort(right[cnt].begin(), right[cnt].end());
        }

        long long total =
            accumulate(nums.begin(), nums.end(), 0LL);

        long long ans = LLONG_MAX;

        for (int cnt = 0; cnt <= n; cnt++) {
            auto &A = left[cnt];
            auto &B = right[n - cnt];

            for (long long x : A) {
                long long target = total / 2 - x;

                auto it = lower_bound(B.begin(), B.end(), target);

                if (it != B.end()) {
                    long long chosen = x + *it;
                    ans = min(ans, llabs(total - 2 * chosen));
                }

                if (it != B.begin()) {
                    --it;

                    long long chosen = x + *it;
                    ans = min(ans, llabs(total - 2 * chosen));
                }
            }
        }

        return (int)ans;
    }
};