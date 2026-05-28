class Solution {
public:
    bool containsDuplicate(vector<int> & nums) {
        switch (nums.size()){
            case 1:
                return false;
            case 2:
                return nums.front() == nums.back();
        }

        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i - 1]){
                return true;
            }   
        }
        return false;
    }
};