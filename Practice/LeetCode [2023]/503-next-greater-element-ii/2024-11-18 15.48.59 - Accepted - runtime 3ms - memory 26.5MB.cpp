class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> toFind;

        for (int i = 0; i < 2 * n; i++) {
            int num = nums[i % n];
            while (!toFind.empty() && nums[toFind.top()] < num) {
                result[toFind.top()] = num;
                toFind.pop();
            }
            
            if (i < n) {
                toFind.push(i);
            }
        }
        return result;
    }
};