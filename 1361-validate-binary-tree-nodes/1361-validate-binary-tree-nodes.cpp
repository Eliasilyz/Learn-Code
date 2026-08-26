class Solution {
public:
    
    int cnt(vector<int> &l, vector<int> &r, int root) {
        if(root == -1) {
            return 0;
        }
        return 1 + cnt(l, r, l[root]) + cnt(l, r, r[root]);
        
    }
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        vector<int> in_deg(n, 0);
        for(int i = 0; i < l.size(); i++) {
            if(l[i] != -1) {
                in_deg[l[i]]++;
                if(in_deg[l[i]] > 1) {
                    return false;
                }
                
            }
            
            if(r[i] != -1) {
                in_deg[r[i]]++;
                if(in_deg[r[i]] > 1) {
                    return false;
                }
            }
        }
        int root = -1;
        for(int i = 0; i < n; i++) {
            if(in_deg[i] == 0) {
                if(root != -1) {
                    return false;
                }
                else {
                    root = i;
                }
            }
        }
        if(root == -1) {
            return false;
        }
        return cnt(l, r, root) == n;
    }
};