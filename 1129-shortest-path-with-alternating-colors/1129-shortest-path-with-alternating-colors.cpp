class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        unordered_map<int,vector<pair<int,int>> > umap;
        for(auto a:redEdges) umap[a[0]].push_back({a[1],0});
        for(auto a:blueEdges) umap[a[0]].push_back({a[1],1});

        unordered_map<int,int> distance;
        for(int i=0;i<n;i++) distance[i]=INT_MAX;
        queue<pair<int,int>> que;
        que.push({0,-1});
        distance[0]=0;
        set<pair<int,int>> st;
        st.insert({0,-1});

        int dist=0;
        while(que.size()){
            int size=que.size();
            while(size--){
                auto tp=que.front();
                que.pop();
                
                for(auto ngh:umap[tp.first]){
                    if(ngh.second!=tp.second&&!st.count({ngh.first,ngh.second})){
                        distance[ngh.first]=min(distance[ngh.first],dist+1);
                        st.insert({ngh.first,ngh.second});
                        que.push({ngh.first,ngh.second});
                    }
                }
            }
            dist++;
        }
        vector<int> ans(n,-1);
        for(auto i:distance){
            ans[i.first]=(i.second==INT_MAX)?-1:i.second;
        }
        return ans;

    }
};