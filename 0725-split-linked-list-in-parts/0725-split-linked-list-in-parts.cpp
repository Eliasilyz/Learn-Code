class Solution {
public:
    
    int solve(ListNode* head) {
        int cnt = 0;
        while(head) {
            head  = head->next;
            cnt++;
        }
        return cnt;
    }
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> parts(k, nullptr);
        int len = solve(root);
        // for (ListNode* node = root; node; node = node->next)
        //     len++;
        int n = len / k, r = len % k; // n : minimum guaranteed part size; r : extra nodes spread to the first r parts;
        ListNode* node = root, *prev = nullptr;
        for (int i = 0; node && i < k; i++, r--) {
            parts[i] = node;
            for (int j = 0; j < n + (r > 0); j++) {
                prev = node;
                node = node->next;
            }
            prev->next = nullptr;
        }
        return parts;
    }
};
