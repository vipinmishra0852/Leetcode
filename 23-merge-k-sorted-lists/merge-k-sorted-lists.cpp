
class Solution {
public:
    ListNode* merge(ListNode* list1, ListNode* list2)
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

    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if(arr.size()==0) return NULL;
        while(arr.size()>1)
        {
            ListNode* a=arr[arr.size()-1];
            arr.pop_back();
            ListNode* b=arr[arr.size()-1];
            arr.pop_back();
           ListNode* c = merge(a,b);
           arr.push_back(c);
        }
        return arr[0];
    }
};