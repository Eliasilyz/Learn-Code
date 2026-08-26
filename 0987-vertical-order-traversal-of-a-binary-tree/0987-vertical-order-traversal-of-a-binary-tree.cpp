/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

bool cmpr(pair<int,int> &a, pair<int,int> &b){
    if(a.second < b.second){
        return true;
    }else if(a.second > b.second){
        return false;
    }else{
        return a.first < b.first;
    }
}
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        q.push({NULL, -1});
        vector<vector<pair<TreeNode*,int>>> ans;
        vector<pair<TreeNode*,int>> ds;
        while(!q.empty()){
            pair<TreeNode*,int> front = q.front();
            q.pop();
            if(front.first == NULL){
                ans.push_back(ds);
                ds.clear();
                if(!q.empty()){
                    q.push({NULL, -1});
                }
            }else{
                ds.push_back(front);
                if(front.first->left != NULL){
                    q.push({front.first->left, front.second - 1});
                }
                
                if(front.first->right != NULL){
                    q.push({front.first->right, front.second + 1});
                }
            }
        }
        //val, level
        map<int, vector<pair<int,int>>> umap;
        for(int i=0;i<ans.size();i++){
            for(auto j : ans[i]){
                umap[j.second].push_back({j.first->val, i});
            }
        }
        vector<vector<int>> ans2;
        for(auto &i : umap){
            sort(i.second.begin(), i.second.end(), cmpr);
            vector<int> temp;
            for(auto j : i.second){
                temp.push_back(j.first);
                // cout<<j.first<<" "<<j.second<<" : ";
            }
            // cout<<endl;
           ans2.push_back(temp);
        }
        return ans2;
    }
};