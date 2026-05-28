class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        // Step 1: Sort nums to process the smallest elements first
        sort(nums.begin(), nums.end());
        
        // Step 2: Compute the prefix sums
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        
        // Step 3: Process each query with binary search
        vector<int> results;
        for (int query : queries) {
            // Binary search to find the largest index where prefix[index] <= query
            int left = 0, right = nums.size() - 1, answer = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (prefix[mid] <= query) {
                    answer = mid;  // Keep track of the valid index
                    left = mid + 1; // Search for a larger index
                } else {
                    right = mid - 1; // Search for a smaller index
                }
            }
            // The size of the subsequence is answer + 1 (index + 1)
            results.push_back(answer + 1);
        }
        
        return results;
    }
};