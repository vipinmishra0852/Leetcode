class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ios::sync_with_stdio(false);

        cin.tie(NULL);
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};