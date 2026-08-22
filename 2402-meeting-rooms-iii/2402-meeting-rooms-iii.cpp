class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> available;

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busy;

        for (int i = 0; i < n; i++) {
            available.push(i);
        }

        vector<int> count(n, 0);

        for (auto &m : meetings) {
            long long start = m[0];
            long long end = m[1];
            long long duration = end - start;

            // Bebaskan semua room yang sudah selesai
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            if (!available.empty()) {
                // Ada room kosong
                int room = available.top();
                available.pop();

                busy.push({end, room});
                count[room]++;
            } else {
                // Semua room sedang dipakai
                auto [finish, room] = busy.top();
                busy.pop();

                long long newEnd = finish + duration;

                busy.push({newEnd, room});
                count[room]++;
            }
        }

        int ans = 0;

        for (int i = 1; i < n; i++) {
            if (count[i] > count[ans]) {
                ans = i;
            }
        }

        return ans;
    }
};