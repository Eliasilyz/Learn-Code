class Solution {
public:
    
    int n;
    
    void solve(vector<int>& nums,int i,int sum,int count,int sz,unordered_map<int,unordered_set<int>> &m)
    {  
        if(i==sz) 
        {
			//storing n*sum from eqn 1.
            m[count].insert(sum*n);
            return ;
        }
        
        solve(nums,i+1,sum+nums[i],count+1,sz,m);
        solve(nums,i+1,sum,count,sz,m);
    }
    
    bool splitArraySameAverage(vector<int>& nums) {
        
        n=nums.size();
        
        int sum=0;
        
        for(auto &x:nums) sum+=x;
        
        unordered_map<int,unordered_set<int>> m1,m2;
      
        //m1[x] stores all possible sum of length x made up of from left half
        //m2[x] stores all possible sum of length x made up of from right half
        solve(nums,0,0,0,n/2,m1);
        solve(nums,n/2,0,0,n,m2);
        
        for(auto &x:m1)
        {
            for(auto &y:x.second)
            { 
                for(auto &z:m2)
                {
                    int a=x.first,b=z.first;
                    
                    if(a+b==0 || a+b==n) continue;
                    
                    if(m2[b].find((a+b)*sum-y)!=m2[b].end()) return true;
                }
            }
        }
        
        return false;
        
    }
};