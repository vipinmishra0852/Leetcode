class Solution {
public:
ListNode* oddEvenList(ListNode* head) {
if(!head or !head->next)return head;
ListNode *odd=head;
ListNode *eve=head->next;
ListNode *newhead=eve;
while(eve and eve->next){
odd->next=eve->next;
odd=odd->next;
eve->next=odd->next;
eve=eve->next;
}
odd->next=newhead;
return head;
}
};