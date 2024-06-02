
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {   
        ListNode* temp1=list1;
        ListNode* temp2=list1;
        ListNode* t=list2;
        int count=1;
        while(count!=a)
        {
            temp1=temp1->next;
            count++;
            
        }
        count=0;
        while(count!=b)
        {
           temp2=temp2->next;
           count++; 
        }
        bool flag=false;
        if(temp2->next!=NULL)
        {
        temp2=temp2->next;
        flag=true;
        }
        temp1->next=t;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        if(flag) t->next=temp2;
        
      
        return list1;

        



    }
};