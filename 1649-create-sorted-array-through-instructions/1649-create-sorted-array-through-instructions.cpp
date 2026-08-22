class Solution {
public:
    static const int MOD = 1e9 + 7;

    int query(vector<int>& bit, int x) {
        int sum = 0;
        while (x > 0) {
            sum += bit[x];
            x -= x & -x;
        }
        return sum;
    }

    void update(vector<int>& bit, int x) {
        while (x < bit.size()) {
            bit[x]++;
            x += x & -x;
        }
    }

    int createSortedArray(vector<int>& instructions) {
        int mx = 100000;
        vector<int> bit(mx + 1, 0);

        long long ans = 0;
        int inserted = 0;

        for (int x : instructions) {
            // jumlah yang strictly less dari x
            int less = query(bit, x - 1);

            // jumlah yang <= x
            int leq = query(bit, x);

            // jumlah yang strictly greater dari x
            int greater = inserted - leq;

            ans = (ans + min(less, greater)) % MOD;

            update(bit, x);
            inserted++;
        }

        return ans;
    }
};