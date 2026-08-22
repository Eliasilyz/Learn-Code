class Solution {
public:
    vector<int> getDist(vector<int>& edges, int start) {
        int n = edges.size();
        vector<int> dist(n, -1);

        int cur = start;
        int d = 0;

        while (cur != -1 && dist[cur] == -1) {
            dist[cur] = d++;
            cur = edges[cur];
        }

        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> d1 = getDist(edges, node1);
        vector<int> d2 = getDist(edges, node2);

        int ans = -1;
        int best = INT_MAX;

        for (int i = 0; i < edges.size(); i++) {
            if (d1[i] == -1 || d2[i] == -1)
                continue;

            int mx = max(d1[i], d2[i]);

            if (mx < best) {
                best = mx;
                ans = i;
            }
        }

        return ans;
    }
};