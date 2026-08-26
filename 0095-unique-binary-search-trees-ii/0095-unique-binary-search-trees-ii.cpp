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
   
    TreeNode *insertBST(TreeNode *root, int val)
    {
        if (root == NULL)
            return new TreeNode(val);
        if (val == root->val)
            return root;
        else if (val < root->val)
            root->left = insertBST(root->left, val);
        else
            root->right = insertBST(root->right, val);
        return root;
    }
    string serializeBST(TreeNode *root){
        queue<TreeNode*> q;
        string s = "";
        q.push(root);
        while(!q.empty()){
            int n  = q.size();
            for(int i = 0 ;i<q.size();i++){
                TreeNode *front = q.front();
                q.pop();
                if(front == NULL){
                    s.append("NULL");
                    continue;
                }else{
                    s.append(to_string(root->val));
                }
                q.push(front->left);
                q.push(front->right);
            }
        }
        return s;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0){
            return {};
        }
        vector<int> arr;
        unordered_map<string, TreeNode*> map;
        vector<TreeNode *> ans;
        for(int i = 1;i<=n;i++){
            arr.push_back(i);
        }
        
        do{
            TreeNode *root = NULL;
            for(int i = 0;i<n;i++){
                root = insertBST(root, arr[i]);
            }
            map[serializeBST(root)] = root;
            for(auto i : arr){
                cout<<i<<' ';
            }            
            cout<<endl;
        }while(next_permutation(arr.begin(), arr.end()));
        for(auto i : map){
            ans.push_back(i.second);
        }
        return ans;        
    }
};