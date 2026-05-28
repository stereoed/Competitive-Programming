class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        stack<int> toFind;

        for (int i = 2 * n - 1; i > -1; i--) {
            while(!toFind.empty() && nums[i%n] >= toFind.top()) toFind.pop();
            if (i < n) {
                if (!toFind.empty()) result[i] = toFind.top();
                else result[i] = -1;
            }
            toFind.push(nums[i%n]);
        }
        return result;
    }
};