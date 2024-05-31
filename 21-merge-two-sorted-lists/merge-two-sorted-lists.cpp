
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
       ListNode* t=new ListNode(100);
       ListNode* temp=t;

       while(list1!=NULL && list2!=NULL)
       {
        if(list1->val<=list2->val)
        {
            temp->next=list1;
            list1=list1->next;
            temp=temp->next;
        }
        else
        {
          temp->next=list2;
          list2=list2->next;
          temp=temp->next;
        }
       }
     if(list1==NULL) temp->next=list2;
     else temp->next=list1;
     return t->next;
    }
};