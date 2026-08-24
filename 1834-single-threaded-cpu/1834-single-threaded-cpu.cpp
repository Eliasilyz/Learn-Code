class comp{
public:
    
    int operator()(const vector<int> &p, vector<int> &q) {
        
        if(p[1] > q[1])
            return true;
        
        return p[1] == q[1] and p[2] > q[2];
    }
};

class Solution {
public:
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        priority_queue<vector<int>, vector<vector<int>>, comp> jobs;
        
        int n = tasks.size();
        for(int i=0; i<n; i++) {
            
            tasks[i].push_back(i);
        }
        
        sort(tasks.begin(), tasks.end());
        
        long long time = tasks[0][0];
        int i = 1;
        
        vector<int> ans;
        
        jobs.push(tasks[0]);
        
        while(!jobs.empty()) {
            
            vector<int> currjob = jobs.top();
            jobs.pop();
            
            ans.push_back(currjob[2]);
            time += currjob[1];
            
           if(jobs.empty() and i<n and time < (long long)tasks[i][0])
               time = tasks[i][0];
            
            while(i<n) {
                
                if(tasks[i][0] <= time) {
                    
                    jobs.push(tasks[i]);
                    i++;
                } else
                    break;
            }
        }
        
        return ans;
    }
};