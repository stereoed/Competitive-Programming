class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int low = nums[0], sum = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if (sum < 1 && sum < low) low = sum;
        }
        return max(1, 1 - low);
    }
};