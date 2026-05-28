class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> o(nums.size(), 1);

        // First, forward pass
        for (int i = 1; i < nums.size(); i++) {
            o[i] = o[i - 1] * nums[i - 1];
        }

        int rightProduct = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            o[i] *= rightProduct; // Multiply the existing left product by the
                                  // right product
            rightProduct *= nums[i]; // Update the right product
        }

        return o;
    }
};