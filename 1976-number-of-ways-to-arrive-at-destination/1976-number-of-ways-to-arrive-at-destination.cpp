class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int M=1e9+7;
        if(n==2)
            return 1;
        if(n==1)
            return 1;
        unordered_map<long long,list<pair<long long,long long>>> adj;
        for(int i=0;i<roads.size();i++)
        {
            long long u=roads[i][0];
            long long v=roads[i][1];
            long long w=roads[i][2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        set<pair<long long,long long>> st;
        vector<long long> distance(n,LONG_MAX);
        vector<long long> path(n,0);
        distance[0]=0;
        path[0]=1;
        
        st.insert({0,0});
        
        while(!st.empty())
        {
            auto top=*(st.begin());
            st.erase(st.begin());
            long u=top.second;
            
            for(auto it:adj[u])
            {
                long long v=it.first;
                long long wt=it.second;
                
                if(distance[v]>(distance[u])+wt)
                {
                    auto findNode=st.find({distance[v],v});
                    if(findNode!=st.end())
                        st.erase(findNode);
                    
                    distance[v]=(distance[u]+wt);
                    path[v]=path[u];
                    st.insert({distance[v],v});
                }
                else if(distance[v]==distance[u]+wt)
                {
                    path[v]=(path[v]+path[u])%M;
                }
            }
        }
        return path[n-1]%M;
    }
};