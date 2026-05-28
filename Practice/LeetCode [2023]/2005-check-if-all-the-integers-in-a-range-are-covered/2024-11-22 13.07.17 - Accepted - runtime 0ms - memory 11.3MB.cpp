class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> prefix(52, 0); // Use size 52 because range [1, 50] is given

        // Mark the start and end of coverage
        for (const auto& range : ranges) {
            prefix[range[0]] += 1;      // Mark the start of the range
            prefix[range[1] + 1] -= 1; // Mark the end of the range
        }

        // Build the prefix sum array
        for (int i = 1; i <= 50; ++i) {
            prefix[i] += prefix[i - 1];
        }

        // Check if all positions in [left, right] are covered
        for (int i = left; i <= right; ++i) {
            if (prefix[i] <= 0) {
                return false; // If a position is not covered, return false
            }
        }

        return true; // All positions in the range are covered
    }
};