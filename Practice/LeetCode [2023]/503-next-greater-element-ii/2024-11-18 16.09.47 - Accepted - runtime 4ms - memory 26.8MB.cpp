class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);  // Initialize all elements to -1
        stack<int> toFind;

        for (int i = 2 * n - 1; i >= 0; --i) {
            int curr = nums[i % n];  // Precompute the current value
            while (!toFind.empty() && toFind.top() <= curr) {
                toFind.pop();  // Maintain monotonicity
            }
            if (i < n && !toFind.empty()) {
                result[i] = toFind.top();  // Update result for the first pass
            }
            toFind.push(curr);  // Push current value
        }
        return result;
    }
};
