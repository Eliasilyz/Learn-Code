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
    ListNode * insertAtEnd(ListNode *head,ListNode *temp){
        temp->next = NULL;
        if(head == NULL)
            return temp;
        ListNode *t = head;
        while(t->next != NULL){
            t=t->next;
        }
        t->next = temp;
        return head;
    }
    void reorderList(ListNode* head) {
       vector<ListNode *> arr;
        ListNode *temp = head;
        while(temp != NULL){
            arr.push_back(temp);
            temp = temp->next;
        }
        ListNode *temp2 = NULL;
        int i = 0, j = arr.size()-1;
        while(i<=j){
            temp2 = insertAtEnd(temp2, arr[i]);
            if(i != j)
                temp2 = insertAtEnd(temp2, arr[arr.size() - i - 1]);
            i++;
            j--;
        }
        head = temp2;      
    }
};