class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), o = 0, sums = 0;
        unordered_map<int, bool> twoSumCheapCopy{{0, true}};
        for (int end = 0; end < n; end++){
            sums += nums[end];
            cout << "have: " << sums << ". Need: " << sums - k << endl;
            if (twoSumCheapCopy[sums - k]) o++;
            twoSumCheapCopy[sums] = true;
        }
        return o;
    }
};