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
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            vector<TreeNode*> arr;
            for(int i = 0; i < n; i++){
                auto f = q.front();
                arr.push_back(f);
                q.pop();
            }
            if(level%2){
                for(int i = 0; i < n/2; i++){
                    swap(arr[i]->val, arr[n -i -1]->val);
                }
            }
            for(int i = 0; i < n; i++){
                auto f = arr[i];
                if(f->left != NULL)q.push(arr[i]->left);
                if(f->right != NULL)q.push(arr[i]->right);
            }
            level++;
        }
        return root;
    }
};