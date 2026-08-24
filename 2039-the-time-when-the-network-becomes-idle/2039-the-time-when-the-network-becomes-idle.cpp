class Solution {
public:
    bool check(vector<vector<int>> &adj, vector<int> &dist, vector<int>& patience, int mid){
        int time = 0;
        int n = adj.size();
        for(int i = 1; i < n; i++){
            int t = dist[i] * 2;
            int extra = t/patience[i];
            if(t%patience[i] == 0){
                extra --;
            }
            int last = t - extra * patience[i];
            time = max(time, t - last + t);
        }
        return time <= mid;
    }
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adj(n);
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> dist(n, 1e9);
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(0);
        dist[0] = 0;
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            
            for(auto i : adj[t]){
                if(dist[t] + 1 < dist[i]){
                    dist[i] = dist[t] + 1;
                    pq.push(i);
                }
            }
        }
        
        long long lo = 0, hi = 1e9, ans = -1;
        while(lo <= hi){
            long long m = (lo + hi)/2;
            if(check(adj, dist, patience, m)){
                hi = m - 1;
                ans = m;
            }else{
                lo = m + 1;
            }
        }
        return ans + 1;
    }
};