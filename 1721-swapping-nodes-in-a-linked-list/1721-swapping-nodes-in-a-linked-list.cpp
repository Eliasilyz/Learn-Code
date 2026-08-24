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
    int length(ListNode* head) {
        int i=0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            i++;
            temp = temp->next;
        }
        return i;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = NULL;
        ListNode* sec = NULL;
        ListNode* temp = head;
        int n = length(head);
        int itr = 1;
        while(temp != NULL){ 
            if(itr == k){
                first = temp;
            }
            if(itr == n - k + 1){
                sec = temp;
            }
            temp = temp->next;
            ++itr;            
        }
        swap(first->val, sec->val);
        return head;
    }
    
};