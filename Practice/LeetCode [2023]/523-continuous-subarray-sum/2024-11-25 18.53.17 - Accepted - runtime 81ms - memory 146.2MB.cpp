class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;

        unordered_map<int, int> m;
        m[0] = -1; // Handle edge case where subarray starts at index 0
        int sum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            sum %= k;

            if (m.find(sum) != m.end()) {
                if (i - m[sum] > 1) return true; // Subarray length > 1
            } else {
                m[sum] = i; // Store earliest index for this remainder
            }
        }

        return false;
    }
};