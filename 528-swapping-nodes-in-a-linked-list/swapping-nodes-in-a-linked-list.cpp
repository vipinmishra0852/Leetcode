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
{   ListNode* temp=head;
    int count=1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;
}
    ListNode* swapNodes(ListNode* head, int k)
    { ios::sync_with_stdio(false);
      cin.tie(NULL);
      ListNode* temp1=head;
      ListNode* temp2=head;
      int size=get_size(head);
      int i=1;
      int j=1;
      while(i!=k)
      {
        temp1=temp1->next;
        i++;
      }
      while(j!=size-k+1)
      {
        temp2=temp2->next;
        j++;
      }
      ListNode* t=new ListNode(100);
      t->val=temp1->val;
      temp1->val=temp2->val;
      temp2->val=t->val;
      return head;

    }
};