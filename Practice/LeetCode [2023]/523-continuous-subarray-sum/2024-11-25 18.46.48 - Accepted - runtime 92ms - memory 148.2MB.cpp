class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;

        unordered_map<int, bool> past; // Track previously seen remainders
        nums[0] = nums[0] % k;

        for (int i = 1; i < nums.size(); i++) {
            nums[i] = (nums[i - 1] + nums[i]) % k; // Calculate cumulative sum modulo k
        }

        if (nums[1] == 0) return true; // Check if first subarray is valid

        for (int i = 2; i < nums.size(); i++) {
            past.insert({nums[i - 2], true}); // Mark the remainder from i-2
            if (nums[i] == 0 || past.find(nums[i]) != past.end()) {
                return true; // Check if remainder exists or is zero
            }
        }

        return false;
    }
};