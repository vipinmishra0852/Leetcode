class Solution {
public:
    int get_size(ListNode* head) {
        int c = 0;
        while (head) {
            head = head->next;
            c++;
        }
        return c;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        int size = get_size(head);
        if (size == 2) return head->val + head->next->val;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverseList(slow);
        int maxSum = 0;
        ListNode* firstHalf = head;
        while (secondHalf) {
            maxSum = max(maxSum, firstHalf->val + secondHalf->val);
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return maxSum;
    }
};