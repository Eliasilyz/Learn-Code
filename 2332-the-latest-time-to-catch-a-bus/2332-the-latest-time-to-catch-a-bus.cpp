class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        priority_queue<int,vector<int>,greater<int>> pq;
        unordered_set<int> st;
        for(auto i:passengers){
            st.insert(i);
            pq.push(i);
        }
        
        sort(begin(buses),end(buses));
        // sort(begin(passengers),end(passengers));
        
        // for(auto i:buses) cout<<i<<" ";
        // cout<<endl;
        // for(auto i:passengers) cout<<i<<" ";
        //  cout<<endl;
        int bus=0;
        int ans=0;
        while(bus<buses.size()){
            vector<int> vec;
           
            while(pq.size()&&pq.top()<=buses[bus]&&vec.size()<capacity){
                vec.push_back(pq.top());
                pq.pop();
            } 
            
            if(vec.size()){
                if(!st.count(vec[0]-1))
                    ans=vec[0]-1;
                for(int i=1;i<vec.size();i++){
                    if(vec[i]-vec[i-1]>1&&!st.count(vec[i]-1)) ans=vec[i]-1; 
                }
                if(vec[vec.size()-1]<buses[bus]&&vec.size()<capacity){
                    if(!st.count(buses[bus]))
                        ans=buses[bus];
                }
            }else if(!st.count(buses[bus])) ans=buses[bus];
            // cout<<ans<<" "<<bus<<endl;
            
            
            bus++;
        }
            
        
            return ans;
    }
};