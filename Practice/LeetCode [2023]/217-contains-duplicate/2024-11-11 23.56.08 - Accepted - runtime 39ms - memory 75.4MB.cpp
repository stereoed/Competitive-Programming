class Solution {
public:
    bool containsDuplicate(vector<int> & nums) {
        switch (nums.size()){
            case 1:
                return false;
            case 2:
                return nums.front() == nums.back();
        }

        unordered_set<int> unique(nums.begin(), nums.end());
        return unique.size() < nums.size();
    }
};