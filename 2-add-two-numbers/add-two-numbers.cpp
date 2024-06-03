class Solution {
public:
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        
        while (l1 || l2 || carry) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            head->next = new ListNode(sum % 10);
            head = head->next;
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        
        return dummy->next;
}
};