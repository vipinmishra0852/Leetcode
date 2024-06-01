
class Solution {
public:
   ListNode* reverseList(ListNode* head) {
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* a=NULL;
        ListNode* b=head;
        ListNode* c=head;
        if(head==NULL || head->next==NULL || left==right) return head; 
        int i=1;
       
        while(i<left)
        {   a=b;
            b=b->next;
            i++;
        }
        c=b;
        for (int j = left; j < right; j++) {
            c = c->next;
        }
        ListNode* d=c->next;
      
        c->next=NULL;
        
        ListNode* t=reverseList(b);
        // a->next=t;
        // c=a;
     if (a != NULL) {
            a->next = t;
        } else {
            head = t;
        }

        b->next = d;

        return head;
    }
};