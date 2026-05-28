class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int o = 0, sums = 0;
        unordered_map<int, int> prefixSumCount{{0, 1}};
        for (int num : nums) {
            sums += num;
            if (prefixSumCount.count(sums - k)) {
                o += prefixSumCount[sums - k];
            }
            prefixSumCount[sums]++;
        }
        return o;
    }
};
