class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int o{0};
        stack<int> mnd; // mono decrease

        // Process start;
        for (int i = 0; i < nums.size(); i++) {
            if (mnd.empty() || nums[mnd.top()] > nums[i]) mnd.push(i);
        }

        if (mnd.empty()) return o;
        for (int i = nums.size() - 1; i > -1; i--){
            while (nums[mnd.top()] <= nums[i]){
                o = max(o, i - mnd.top());
                mnd.pop();
                if (mnd.empty()) return o;
            }
        }
        return o;
    }
};