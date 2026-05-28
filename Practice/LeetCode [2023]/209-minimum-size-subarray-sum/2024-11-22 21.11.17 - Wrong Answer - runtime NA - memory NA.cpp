class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0, n = nums.size();
        for (int i = n - 1; i >= 0; i--){
            sum += nums[i];
            if (sum >= target) return n-i;
        }

        return 0;
    }
};