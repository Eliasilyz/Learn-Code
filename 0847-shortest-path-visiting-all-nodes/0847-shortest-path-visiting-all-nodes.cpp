class Solution {
public:
    
    int dp[13][1 << 13];
    
    int dfs(int node, int mask, vector<vector<int> > &graph) {
        if(dp[node][mask] != 0) {
            return dp[node][mask];
        }
        if((mask & (mask - 1)) == 0) {
            return 0;
        }
        
        
        dp[node][mask] =  INT_MAX - 1;
        for(auto neighbour : graph[node]) {
            if((mask & (1 << neighbour)) != 0) {
                dp[node][mask] = min(dp[node][mask], 1 + (min(dfs(neighbour, mask, graph), dfs(neighbour, mask  ^ (1 << node), graph))));
            }
        }
        return dp[node][mask];
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        memset(dp, 0, sizeof dp);
        
        
        
        int ans = INT_MAX;
        int mask = (1 << n) - 1;
        for(int i = 0; i< n; i++) 
        {
            
            ans = min(ans, dfs(i, mask, graph));
            
        }
        return ans;
    }
};