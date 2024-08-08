class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int nse = i;
                int ele = heights[st.top()];
                st.pop();
                int pse = st.empty()? -1 : st.top();
                maxArea = max(maxArea, ele * (nse - pse - 1));
            }
            st.push(i);
        }
        while (!st.empty()) {
            int ele = heights[st.top()];
            st.pop();
            int pse = st.empty()? -1 : st.top();
            int nse = heights.size();
            maxArea = max(maxArea, ele * (nse - pse - 1));
        }

        return maxArea;
    }
};