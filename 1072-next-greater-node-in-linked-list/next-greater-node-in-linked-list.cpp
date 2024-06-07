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
    vector<int> nextLargerNodes(ListNode* head) {
    ios:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     ListNode* temp=head;
     vector<int>v;
     int n = 0;
     while(temp)
     { n++;
       v.push_back(temp->val);
       temp=temp->next;
     }   
     stack<int>st;
     vector<int>nge(n);
     nge[n-1]=0;
     st.push(v[n-1]);
      for (int i = n - 2; i >= 0; i--)
  { // pop all the answer in nge array
    while (st.size() > 0 && st.top() <= v[i])
    {
      st.pop();
    }
    if (st.size() == 0)
      nge[i] = 0;
    else
    {
      // push the element
      nge[i] = st.top();
    }
    st.push(v[i]);
  }

    return nge;
    }
};