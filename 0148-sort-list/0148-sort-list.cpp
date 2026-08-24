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
    ListNode* sortList(ListNode* head) {
        if(head == NULL)return NULL;
        vector<int> arr;
        ListNode *temp = head;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        sort(arr.begin(), arr.end());
        temp = new ListNode(arr[0]);
        ListNode *head2 = temp;
        for(int i = 1; i < arr.size();i++){
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        return head2;
    }
};