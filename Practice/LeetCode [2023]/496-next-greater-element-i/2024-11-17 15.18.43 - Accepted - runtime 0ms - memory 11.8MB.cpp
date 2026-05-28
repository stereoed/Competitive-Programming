class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> result(n, -1);

        // Map to store the next greater element for each value in nums2
        vector<int> next_greater(10001, -1); // All values are <= 10^4
        stack<int> toFind;

        // Compute next greater elements for nums2
        for (int num : nums2) {
            while (!toFind.empty() && toFind.top() < num) {
                next_greater[toFind.top()] = num; // Assign the next greater element
                toFind.pop();
            }
            toFind.push(num);
        }

        // Map values in nums1 to their next greater element
        for (int i = 0; i < n; ++i) {
            result[i] = next_greater[nums1[i]];
        }

        return result;
    }
};
