class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int o{0};
        vector<int> mnd{0}; // mono decrease
        mnd.reserve(nums.size());

        // Process start;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[mnd.back()] > nums[i]) mnd.emplace_back(i);
        }

        if (mnd.empty()) return o;
        for (int i = nums.size() - 1; i > -1; i--){
            while (nums[mnd.back()] <= nums[i]){
                o = max(o, i - mnd.back());
                mnd.pop_back();
                if (mnd.empty()) return o;
            }
        }
        return o;
    }
};