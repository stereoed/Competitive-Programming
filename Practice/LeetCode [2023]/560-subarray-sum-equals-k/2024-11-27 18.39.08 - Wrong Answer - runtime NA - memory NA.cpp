class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), o = 0, sums = 0;
        unordered_map<int, int> twoSumCheapCopy{{0, 1}};
        for (int end = 0; end < n; end++){
            sums += nums[end];
            cout << "have: " << sums << ". Need: " << sums - k << endl;
            if (int a = twoSumCheapCopy[sums - k] > 0) o+=a;
            twoSumCheapCopy[sums]++;
        }
        return o;
    }
};