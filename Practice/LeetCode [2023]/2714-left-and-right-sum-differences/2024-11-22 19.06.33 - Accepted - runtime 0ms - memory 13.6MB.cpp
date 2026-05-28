class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sumToLeft = 0;

        for (int i = 1; i < nums.size(); i++) nums[i] += nums [i - 1];
        for (int i = 0; i < nums.size(); i++){
            int aux = max(nums.back() - nums[i] - sumToLeft, -(nums.back() - nums[i] - sumToLeft));
            sumToLeft = nums[i];
            nums[i] = aux;
        }

        return nums;
    }
};