class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> tc;
        int o = 0, sum = 0;
        tc[0] = -1; // Handle the case where subarray starts from index 0
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] ? 1 : -1;
            if (tc.find(sum) != tc.end()) {
                o = max(o, i - tc[sum]);
            } else {
                tc[sum] = i;
            }
        }
        return o;
    }
};
