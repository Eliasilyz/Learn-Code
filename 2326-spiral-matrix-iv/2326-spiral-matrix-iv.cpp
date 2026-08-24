/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m,vector<int>(n,-1));
        
        int idx=0;
        
        int rowTp=0,rowBt=m-1;
        int colTp=0,colBt=n-1;
        while(head&&rowTp<=rowBt&&colTp<=colBt){
            for(int i=colTp;i<=colBt&&head;i++){
                mat[rowTp][i]=head->val;
                head=head->next;
            }
            rowTp++;
           
            
            for(int i=rowTp;i<=rowBt&&head;i++){
                mat[i][colBt]=head->val;
                head=head->next;
            }
            colBt--;
            
            
            for(int i=colBt;i>=colTp&&head;i--){
                mat[rowBt][i]=head->val;
                head=head->next;
            }
            rowBt--;
            
            for(int i=rowBt;i>=rowTp&&head;i--){
                mat[i][colTp]=head->val;
                head=head->next;
            }
            colTp++;
            
        }
        return mat;
    }
};