class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int count = 0, sum = 0;
        for (const int n : nums){
            sum += n;
            if (sum == 0) count++;
        }

        return count;
    }
};