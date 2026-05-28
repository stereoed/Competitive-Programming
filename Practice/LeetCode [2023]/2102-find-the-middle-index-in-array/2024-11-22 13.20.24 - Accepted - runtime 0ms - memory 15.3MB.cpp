class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int o = nums.size();
        for (int i = 1; i < o; i++) nums[i] += nums[i - 1];
        if (nums[0] == nums.back()) return 0;

        for (int i = 1; i < o; i++) if (nums[i] == nums.back() - nums[i - 1]) return i;
        
        return -1;
    }
};