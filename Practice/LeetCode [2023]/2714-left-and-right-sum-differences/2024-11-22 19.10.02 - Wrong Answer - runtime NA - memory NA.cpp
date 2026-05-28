class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int totalSum = 0, leftSum = 0;
        for (int num : nums) totalSum += num;

        for (int i = 0; i < nums.size(); i++) {
            nums[i] += abs(2 * leftSum - totalSum);
            leftSum += nums[i];
        }

        return nums;
    }
};