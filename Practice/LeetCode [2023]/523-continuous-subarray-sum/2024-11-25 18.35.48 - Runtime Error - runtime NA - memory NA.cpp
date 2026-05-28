class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, bool> past;
        nums[0] = nums[0] % k;
        for (int i = 1; i < nums.size(); i++) nums[i] = (nums[i-1] + nums[i]) % k;
        for (int i = 0; i < nums.size(); i++) cout << nums[i] << " ";

        if (nums[1] == 0) return true;
        for (int i = 2; i < nums.size(); i++){
            past.insert({nums[i - 2], true});
            if (nums[i] == 0 || past[nums[i]]) return true;
        }
        


        return false;
    }
};