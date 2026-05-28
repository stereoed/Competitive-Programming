class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int totalSum = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) totalSum += nums[i];
        cout << totalSum;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (nums[i] == 0 && sum == totalSum - sum + nums[i]) return i - 1;
        }
        return 0;
    }
};