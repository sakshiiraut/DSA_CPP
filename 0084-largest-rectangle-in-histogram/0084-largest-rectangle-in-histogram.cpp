class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsi(n);  // Next Smaller Index
        vector<int> psi(n);  // Previous Smaller Index

        stack<int> st;

        // Finding Previous Smaller Index
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(st.empty())
                psi[i] = -1;
            else
                psi[i] = st.top();
            st.push(i);
        }

        // Clear stack before reuse
        while(!st.empty()) st.pop();

        // Finding Next Smaller Index
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(st.empty())
                nsi[i] = n;
            else
                nsi[i] = st.top();
            st.push(i);
        }

        // Calculate max area
        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            int width = nsi[i] - psi[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
