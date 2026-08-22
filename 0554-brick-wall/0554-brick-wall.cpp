class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> edges;
        int maxEdges = 0;

        for (auto& row : wall) {
            long long pos = 0;

            for (int i = 0; i < row.size() - 1; i++) {
                pos += row[i];

                edges[pos]++;
                maxEdges = max(maxEdges, edges[pos]);
            }
        }

        return wall.size() - maxEdges;
    }
};