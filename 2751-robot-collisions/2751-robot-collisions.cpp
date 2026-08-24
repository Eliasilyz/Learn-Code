class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<int, pair<int, int>>> arr;
        for(int i = 0; i < n; i++){
            int d = 1;
            if(directions[i] == 'L')d = -1;
            arr.push_back({i, {positions[i], healths[i] * d}});
        }
        vector<int> h;
        for(int i = 0; i < n; i++){
             int d = 1;
            if(directions[i] == 'L')d = -1;
            h.push_back(healths[i] * d);
        }
        sort(arr.begin(), arr.end(), [&](pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b){
           if(a.second.first == b.second.first)
               return a.first < b.first;
            return a.second.first <= b.second.first;
        });
        
        // vector<int> h;
        // for(auto i : arr){
        //     h.push_back(i.second.second);
        // }
        stack<int> s;
        for(int i = 0; i < n; i++){
            int ind = arr[i].first;
            if(h[ind] > 0 || s.empty()){
                s.push(ind);
            }else{
                while(!s.empty() and h[s.top()] > 0 and h[s.top()] < abs(h[ind])){
                    h[s.top()] = 0;
                    h[ind]++;
                    if(h[ind] >= 0)
                        h[ind] = 0;
                    s.pop();
                }
                if(!s.empty() and h[s.top()] == abs(h[ind])){
                    h[ind] = -1;
                    h[s.top()] = -1;
                    s.pop();
                }
                else if(!s.empty() and h[s.top()] > abs(h[ind])){
                    h[s.top()]--;
                }
                else{
                    if(s.empty() || h[s.top()] < 0){
                        s.push(ind);
                    }
                }
            }
        }
        vector<pair<int, int>> ans;
        while(!s.empty()){
            ans.push_back({s.top(), abs(h[s.top()])});
            s.pop();
        }
        sort(ans.begin(), ans.end());
        vector<int> t;
        for(auto i : ans){
            t.push_back(i.second);
        }
        
        return t;
    }
};