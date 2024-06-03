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
    int get_size(ListNode* head)
    {   int c=1;
        while(head->next)
        {
        head=head->next;
        c++;
        }
        return c;
    }
    int getDecimalValue(ListNode* head) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        ListNode* temp=head;
        int size=get_size(temp);
        temp=head;
        int ans=0;
        if(size==0) return 0;
        if(size==1) return head->val;
        if(size>1)
        {
        int i=size-1;
        while(temp || i>=0) 
        {
         if(temp->val==1)
        {
          ans=ans+(1<<i);
        }
        temp=temp->next;
        i--;
        }
        }
        return ans;
    }
};