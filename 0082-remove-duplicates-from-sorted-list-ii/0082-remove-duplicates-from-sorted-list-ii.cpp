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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)return NULL;
        map<int, int> umap;
        ListNode *temp = head;
        while(temp != NULL){
            umap[temp->val]++;
            temp = temp->next;
        }
        vector<int> arr;
        for(auto i : umap){
            if(i.second > 1) continue;
            arr.push_back(i.first);
        }
        if(arr.size() == 0)return NULL;
        
        ListNode *head2 = new ListNode(arr[0]);
        ListNode *prev = head2;
        for(int i = 1;i<arr.size();i++){
            prev->next = new ListNode(arr[i]);
            prev = prev->next;
        }
        return head2; 
    }
};