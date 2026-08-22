class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> diff(n + 1, 0);

        long long active = 0;

        for (int i = 0; i < n; i++) {
            active += diff[i];

            long long cur = nums[i] - active;

            if (cur < 0)
                return false;

            if (cur > 0) {
                // Harus melakukan cur operasi mulai dari i
                if (i + k > n)
                    return false;

                active += cur;
                diff[i + k] -= cur;
            }
        }

        return true;
    }
};