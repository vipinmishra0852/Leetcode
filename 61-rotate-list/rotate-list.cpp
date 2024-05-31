
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        int size=1;
        ListNode* temp=head;
        ListNode* tail=head;
        while(tail->next!=NULL)
        {
            size++;
            tail=tail->next;
        }
         int rot=k%size;
        if(rot==0 || rot==size) return head;
        for(int i=1;i<size-rot;i++)
        {
          temp=temp->next;
        }
        ListNode* s=temp->next;
        temp->next=NULL;
        tail->next=head;
        return s;
    }
};