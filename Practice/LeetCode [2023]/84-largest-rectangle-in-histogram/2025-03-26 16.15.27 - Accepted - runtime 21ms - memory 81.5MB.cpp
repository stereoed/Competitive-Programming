class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;
        
        // Iterate one extra time to flush the remaining heights.
        for (int i = 0; i <= n; ++i) {
            // Use 0 as the height for the extra iteration.
            int currHeight = (i == n ? 0 : heights[i]);
            
            while (!st.empty() && currHeight < heights[st.top()]) {
                int top = st.top();
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, heights[top] * width);
            }
            
            st.push(i);
        }
        
        return maxArea;
    }
};