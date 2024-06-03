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
    ListNode* deleteDuplicates(ListNode* head)
    {
     ios::sync_with_stdio(false);
     cin.tie(NULL);
     ListNode* dummy = new ListNode(0);
     dummy->next=head;
     ListNode* temp = dummy;
     while(head!=NULL)  
     {
        if(head->next && head->val == head->next->val)
        {
            while(head->next && head->val == head->next->val)
            {
                head=head->next;
            }
            temp->next=head->next;
        }
        else
        {   temp=temp->next;
            
           
        }
        head=head->next;
      }
      return dummy->next;   
    }
};