class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        int n=s.size();
        string ans="";
         for (char ch : s) {
            if (ch == '(') {
                // If stack is not empty, it's not outermost
                if (!st.empty()) ans += ch;
                st.push(ch);
            } else { // ch == ')'
                st.pop();  // reduce nesting
                // If stack is not empty after popping, it's not outermost
                if (!st.empty()) ans += ch;
            }
        }

        return ans;
    }
};