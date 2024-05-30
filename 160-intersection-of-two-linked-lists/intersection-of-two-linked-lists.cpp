/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* temp=headA;
        ListNode* temp2=headB;
        int lenA=0;
        int lenB=0;
        while(temp!=NULL)   
        {
            lenA++;
            temp=temp->next;
        }
        
         while(temp2!=NULL)
        {
            lenB++;
            temp2=temp2->next;
        }
        temp=headA;
        temp2=headB;
        int n=abs(lenA-lenB);

        if(lenA>=lenB)
        {
          for(int i=1;i<=n;i++)
        {
          temp=temp->next;
        }
        }
        else
        {
          for(int i=1;i<=n;i++)
        {
          temp2=temp2->next;
        }
        }
       while(temp!=temp2)
       {
        temp=temp->next;
        temp2=temp2->next;
       }
     return temp;
    }
};