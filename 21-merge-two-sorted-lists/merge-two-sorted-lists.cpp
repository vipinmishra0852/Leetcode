
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        ListNode* a=list1;
        ListNode* b=list2;
        ListNode* c = new ListNode(100);
        ListNode* tempC=c; 
        while(a!=NULL && b!=NULL)
        {
            if(a->val<=b->val)
            {
              ListNode* e=new ListNode(a->val);
              tempC->next=e;
              tempC=e;
              a=a->next;
                
            }
            else
            {
                ListNode* e= new ListNode(b->val); 
                tempC->next=e;
                tempC=e;
                b=b->next;
            }
        }
        if(a==NULL)
        {
            tempC->next=b;
        }
        else
        {
            tempC->next=a;
        }

        return c->next;
    }
};