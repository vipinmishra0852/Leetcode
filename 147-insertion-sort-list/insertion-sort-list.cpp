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
{
  int count=1;
  ListNode* temp=head;
  while(temp->next!=NULL)
  {
    count++;
    temp=temp->next;
  }
  return count;
}
    ListNode* insertionSortList(ListNode* head) {
      int s = get_size(head);  
      if(s==1) return head;
      vector<int>v(s,0);
      ListNode* t=head;
      int i=0;
      while(t)
      {
        v[i]=t->val;
        t=t->next;
        i++;
      }
      sort(v.begin(),v.end());
      t=head;
      i=0;
      while(t)
      {
        t->val=v[i];
        t=t->next;
        i++;
      }
      return head;
    }
};