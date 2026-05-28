class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int low = nums[0];
        for (int i = 1; i < nums.size(); i++){
            nums[i] += nums[i-1];
            cout << nums[i] << ", ";
            low = min(low, nums[i]);
        }

        return max(1, 1 - low);
    }
};