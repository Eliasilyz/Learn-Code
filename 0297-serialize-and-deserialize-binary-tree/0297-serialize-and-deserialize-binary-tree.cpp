/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode *front = q.front();
                q.pop();
                if(front != NULL){
                    q.push(front->left);
                    q.push(front->right);
                    s.append(to_string(front->val) + ',');
                }else{
                    s.append("#,");
                }
            }
        }
        cout<<s<<endl;
        return s;        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        
        vector<TreeNode *> arr;
        string num = "";
        for(int i = 0;i< data.length(); i++){
            char c = data[i];
            if(c == ','){
                if(data[i-1] == '#'){
                    continue;
                }else{
                    TreeNode *temp = new TreeNode(stoi(num));
                    arr.push_back(temp);
                    num = "";
                }
            }
            else if(c == '#') {
                arr.push_back(NULL);
            }
            else{
                num.push_back(c);
            }
        }
        int pos = 1;
        for(int i = 0;i<arr.size();i++){
            if(arr[i] == NULL) continue;
            arr[i]->left = arr[pos];
            arr[i]->right = arr[pos + 1];
            pos +=2;
        }
        for(auto i : arr){
            if(i == NULL){
                cout<<"NULL"<<' ';
            }else{
                cout<<i->val<<" ";                
            }
        }
        return arr[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));