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
    bool hasCycle(ListNode *head) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        if(!head) return false;
        map<ListNode*,int>mp;
        ListNode* temp = head;
        int size = 0;
        while(temp!=NULL)
        {
            if(mp[temp] == 0)
            {
              mp[temp]++;
              temp = temp->next;
            }
            else
            {
                return true;
            }
            
        }
        return false;
    }
};