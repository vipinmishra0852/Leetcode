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
    
    ListNode* getNode(ListNode* head,int idx )
    {   ListNode* t=head;
        for(int i=1;i<=idx;i++)
        {
           t=t->next;
        }
        return t;
    }
    ListNode* reverseList(ListNode* head)
    { ios::sync_with_stdio(false);
    cin.tie(NULL);
     int n=0;
     ListNode* temp=head;
     while(temp)
     {
        temp=temp->next;
        n++;
     }
     int i=0;
     int j=n-1;
     while(i<j)
     {
        ListNode* left=getNode(head,i);
        ListNode* right=getNode(head,j);
        int c=left->val;
        left->val=right->val;
        right->val=c;
        i++;
        j--;

     }
     temp=head;
     while(temp)
     {
        temp=temp->next;
     }
     return head;   
    }
};