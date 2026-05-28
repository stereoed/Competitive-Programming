class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, n = nums.size(), o = INT_MAX, sums = 0;
        for (int end = 0; end < n; end++){
            sums += nums[end];

            while (sums >= target){
                o = min(o, end - start + 1);
                sums -= nums[start++];
            }
        }

        return o == INT_MAX ? 0 : o;
    }
};