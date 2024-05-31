
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
      if(head==NULL) return NULL;
      if( head->next==NULL) return head;
      ListNode* a=head;
      ListNode* b=head->next;
      
      while(b!=NULL)
      {
        while(b!=NULL && b->val==a->val)
        {
            b=b->next;
        }
        a->next=b;
        a=b;
        if(b!=NULL) b=b->next;
      }
      return head;
      
      
    }
};