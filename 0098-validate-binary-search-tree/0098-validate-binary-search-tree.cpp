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
    TreeNode* prev = NULL;
    bool infix(TreeNode * root){
        if(root == NULL)return true;
        bool b1 = infix(root->left);
        if(prev != NULL){
            if(prev->val >= root->val){
                return false;
            }
        }
        prev = root;
        bool b2 = infix(root->right);
        return (b1 && b2);
    }
    bool isValidBST(TreeNode* root) {
        return infix(root);
    }
};