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
       
     if (a != NULL) {
            a->next = t;
        } else {
            head = t;
        }

        b->next = d;

        return head;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* temp=head;
        int gap=1;
        while(temp && temp->next)
        {
            int remLen=0;
            ListNode* t=temp->next;
            for(int i=1;i<=gap+1 && t!=NULL ;i++)
            {
                t=t->next;
                remLen++;
            }
            if(remLen<gap+1) gap=remLen-1;
            if(gap%2!=0) reverseBetween(temp,2,2+gap);
            gap++;
            for(int i=1;temp!=NULL && i<=gap;i++)
            {
             temp=temp->next;
            }
        }
        return head;
    }
};