class Solution {
public:
    int get_size(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode* get_element(ListNode* head, int idx) {
        ListNode* temp = head;
        int count = 0;
        while (temp != nullptr && count < idx) {
            temp = temp->next;
            count++;
        }
        return temp;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int s = get_size(head);
        int idx_to_remove = s - n;
        
        if (idx_to_remove == 0) {
          
            ListNode* new_head = head->next;
            delete head;
            return new_head;
        }

        ListNode* prev = get_element(head, idx_to_remove - 1);
        ListNode* node_to_remove = prev->next;
        prev->next = node_to_remove->next;
        delete node_to_remove;
        return head;
    }
};