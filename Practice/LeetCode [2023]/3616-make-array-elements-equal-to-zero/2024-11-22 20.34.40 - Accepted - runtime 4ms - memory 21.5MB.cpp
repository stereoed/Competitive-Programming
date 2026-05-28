class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0, validSelections = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) { // Only consider starting points with nums[i] == 0
                int a = abs(totalSum - 2 * sum + nums[i]);
                if (a <= 1) {
                    validSelections += 2 - a; // Both left and right directions are valid
                }
            }
            sum += nums[i];
        }

        return validSelections;
    }
};