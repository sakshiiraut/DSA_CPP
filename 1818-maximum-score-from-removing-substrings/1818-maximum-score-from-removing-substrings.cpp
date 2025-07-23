class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char first1 = 'a', first2 = 'b';
        int val1 = x, val2 = y;

        if (x < y) {
            swap(first1, first2);
            swap(val1, val2);
        }

        stack<char> st;
        string temp = "";
        int score = 0;

        for (char c : s) {
            if (!st.empty() && st.top() == first1 && c == first2) {
                st.pop();
                score += val1;
            } else {
                st.push(c);
            }
        }

        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());

        for (char c : temp) {
            if (!st.empty() && st.top() == first2 && c == first1) {
                st.pop();
                score += val2;
            } else {
                st.push(c);
            }
        }

        return score;
    }
};
