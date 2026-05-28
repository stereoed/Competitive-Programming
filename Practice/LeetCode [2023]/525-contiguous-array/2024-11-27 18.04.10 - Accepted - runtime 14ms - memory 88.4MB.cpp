class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> tc{{0, -1}}; // Initialize with base case
        int o = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] ? 1 : -1;
            if (tc.count(sum)) {
                o = max(o, i - tc[sum]);
            } else {
                tc[sum] = i;
            }
        }
        return o;
    }
};
