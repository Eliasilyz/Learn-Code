class Solution {
public:
    map<int, vector<int> > m;
    map<int, int> count;
    map<int, int> stSum;
    vector<int> ans;
    int N;
    
    
    void dfs1(int node, int parent) {
        for(auto child : m[node]) {
            if(child != parent) {
                dfs1(child, node);
                count[node] += count[child];
                stSum[node] += count[child] + stSum[child];
            }
        }
    }
    
    void dfs2(int node, int parent) {
        for(auto child : m[node]) {
            if(child != parent) {
                stSum[child] = stSum[node] - count[child] + N - count[child];
                dfs2(child, node);
            }
        }
    }
    
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        for(auto i: edges) {
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        
        for(int i = 0; i < n; i++)  {
            stSum[i] = 0;
            count[i] = 1;
        }
        N = n;
        dfs1(0, -1);
        dfs2(0, -1);
        // vector<int> ans;
        for(int i = 0; i < n; i++) {
            ans.push_back(stSum[i]);
        }
        return ans;
        
        
        
    }
};