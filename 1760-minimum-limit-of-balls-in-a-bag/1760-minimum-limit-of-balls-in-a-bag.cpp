class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        long long left = 1;
        long long right = *max_element(nums.begin(), nums.end());

        while (left < right) {
            long long mid = left + (right - left) / 2;

            long long operations = 0;

            for (long long num : nums) {
                operations += (num - 1) / mid;

                if (operations > maxOperations)
                    break;
            }

            if (operations <= maxOperations) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};