class Solution {
public:
    int removePair(string &s, char first, char second) {
        stack<char> st;
        int count = 0;

        for (char ch : s) {
            if (!st.empty() && st.top() == first && ch == second) {
                st.pop();
                count++;
            } else {
                st.push(ch);
            }
        }

        string temp;
        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        s = temp;
        return count;
    }

    int maximumGain(string s, int x, int y) {
        int score = 0;
        if (x > y) {
            score += x * removePair(s, 'a', 'b');
            score += y * removePair(s, 'b', 'a');
        } else {
            score += y * removePair(s, 'b', 'a');
            score += x * removePair(s, 'a', 'b');
        }
        return score;
    }
};
