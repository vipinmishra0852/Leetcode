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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next; // Skip the initial zero node
        ListNode* current = head;    // Pointer to place sums
        int sum = 0;

        while (temp != nullptr) {
            if (temp->val != 0) {
                sum += temp->val;
            } else {
                current->val = sum;  // Place the sum in the previous zero node
                sum = 0;
                if (temp->next != nullptr) {
                    current->next = temp; // Move current to the next zero node
                    current = current->next;
                } else {
                    current->next = nullptr; // End of list, make sure to set next to nullptr
                }
            }
            temp = temp->next;
        }
        return head;
    }
};
