class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0, validSelections = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) { // Only consider starting points with nums[i] == 0
                int difference = totalSum - 2 * sum + nums[i];
                if (difference == 0) {
                    validSelections += 2; // Both directions valid
                } else if (difference == 1 || difference == -1) {
                    validSelections += 1; // Only one direction valid
                }
            }
            sum += nums[i];
        }

        return validSelections;
    }
};