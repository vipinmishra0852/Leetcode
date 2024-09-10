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
    int gcd(int val1,int val2)
    {
        int n = min(val1,val2);
        for(int i=n;i>=2;i--)
        {
            if( (val1%i == 0) && (val2%i==0)) return i;
        }
        return 1;
    } 
    ListNode* insertGreatestCommonDivisors(ListNode* head)
    {
       ListNode* temp = head;
       ListNode* temp1 = head;
       while(temp->next!= NULL)
       {
        ListNode* m = new ListNode();
        int i = gcd(temp->val,temp->next->val);
        m->val = i;
         temp=temp->next;
        
        m->next = temp1->next;
        temp1->next = m;
        temp1 = temp1->next->next;
       
       } 
       return head;
    }
};