class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b)
            parent[b] = a;
    }

    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> ans(m, vector<int>(n));

        parent.resize(m * n);
        iota(parent.begin(), parent.end(), 0);

        vector<pair<int, pair<int, int>>> cells;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                cells.push_back({matrix[r][c], {r, c}});
            }
        }

        sort(cells.begin(), cells.end());

        vector<int> rowRank(m, 0);
        vector<int> colRank(n, 0);

        int i = 0;

        while (i < cells.size()) {
            int j = i;

            while (j < cells.size() &&
                   cells[j].first == cells[i].first) {
                j++;
            }

            for (int k = i; k < j; k++) {
                int r = cells[k].second.first;
                int c = cells[k].second.second;

                parent[r * n + c] = r * n + c;
            }

            unordered_map<int, int> rowSeen;
            unordered_map<int, int> colSeen;

            for (int k = i; k < j; k++) {
                int r = cells[k].second.first;
                int c = cells[k].second.second;
                int id = r * n + c;

                if (rowSeen.count(r))
                    unite(id, rowSeen[r]);
                else
                    rowSeen[r] = id;

                if (colSeen.count(c))
                    unite(id, colSeen[c]);
                else
                    colSeen[c] = id;
            }

            unordered_map<int, int> componentRank;

            for (int k = i; k < j; k++) {
                int r = cells[k].second.first;
                int c = cells[k].second.second;

                int root = find(r * n + c);

                int rank = max(rowRank[r], colRank[c]) + 1;

                componentRank[root] =
                    max(componentRank[root], rank);
            }

            for (int k = i; k < j; k++) {
                int r = cells[k].second.first;
                int c = cells[k].second.second;

                int root = find(r * n + c);
                int rank = componentRank[root];

                ans[r][c] = rank;

                rowRank[r] = max(rowRank[r], rank);
                colRank[c] = max(colRank[c], rank);
            }

            i = j;
        }

        return ans;
    }
};