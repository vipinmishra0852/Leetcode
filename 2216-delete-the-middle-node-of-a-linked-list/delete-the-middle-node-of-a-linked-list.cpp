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
    ListNode* middle(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* p=slow;
         while(fast->next!=NULL)
        {
            if(fast->next->next==NULL)
            {   p=slow;
                slow=slow->next;
                break;
            }
            else
            {   p=slow;
                slow=slow->next;
                fast=fast->next->next;
            }
        }
       return p;

    }
    ListNode* deleteMiddle(ListNode* head) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
      if(head==NULL) return head;
      if( head->next==NULL)
      {
        return NULL;
      }
      if( head->next->next==NULL)
      {
        head->next=NULL;
        return head;
      }
      ListNode* t=head;
      ListNode* d=middle(t);
      d->next=d->next->next;
    //   d->next=NULL;
      return head;
    }
};