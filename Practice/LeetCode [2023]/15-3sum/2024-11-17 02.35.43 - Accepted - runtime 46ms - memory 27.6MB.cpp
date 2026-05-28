class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // Sort the array

        if (*nums.begin() == *(nums.end() - 1)){
            if (*nums.begin() == 0){
                return {{0, 0, 0}};
            }
            return {};
        }

        if (*nums.begin() > 0 || *(nums.end() - 1) < 0){
            return {};
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // Skip duplicates for the first element
            }

            int left = i + 1, right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back(vector<int>{nums[i], nums[left],
        nums[right]});

                    // Skip duplicates for the second and third elements
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};