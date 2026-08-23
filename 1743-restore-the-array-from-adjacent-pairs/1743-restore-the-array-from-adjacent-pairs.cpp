class Solution {
public:
    void recur(vector<int> &ans,set<int>& vis, int node,unordered_map<int,vector<int>>& um)
    {
        if(vis.find(node)!=vis.end()) return;
        
        vis.insert(node);
        
        
        ans.push_back(node);
        
        for(auto a : um[node]) recur(ans,vis,a,um);
    }
    
    
    
    vector<int> restoreArray(vector<vector<int>>& adj) {
        
        
        unordered_map<int,vector<int>> um;
        
        for(int i=0;i<adj.size();i++)
        {
            um[adj[i][0]].push_back(adj[i][1]);
            um[adj[i][1]].push_back(adj[i][0]);
        }
        
        
        int head;
        vector<int> ans;
        set<int> vis;
        for(auto a: um)
        {
            if(a.second.size()==1)
            {
                head = a.first;
                break;
                
            }
        }
        recur(ans,vis,head,um);
        return ans;
    }
};