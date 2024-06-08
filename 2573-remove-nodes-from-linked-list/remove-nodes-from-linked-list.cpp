class Solution {
public:
    int get_size(ListNode* temp) {
        int n = 0;
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }
        return n;
    }

    ListNode* removeNodes(ListNode* head) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* temp = head;
        int n = get_size(temp);
        temp = head;
        vector<int> v;

        while (temp != nullptr) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> nge(n, -1);
        stack<int> st;
        st.push(v[n - 1]);

        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() && st.top() <= v[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[i] = st.top();
            }
            st.push(v[i]);
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nge[i] == -1) {
                ans.push_back(v[i]);
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* h = dummy;
        temp = head;
        int i = 0;

        while (temp != nullptr && i < ans.size()) {
            if (temp->val == ans[i]) {
                h->next = new ListNode(temp->val);
                h = h->next;
                i++;
            }
            temp = temp->next;
        }

        return dummy->next;
    }
};