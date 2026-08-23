class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& op) {
        unordered_map<int,int> umap;
        unordered_map<int,int> con;
        for(auto i:nums){
            con[i]=i;
        }
        for(auto i:op){
            umap[con[i[0]]]=i[1];
            con[i[1]]=con[i[0]];
        }
        for(auto &i:nums){
            if(umap.count(i)){
                i=umap[i];
            }
        }
        return nums;
    }
};