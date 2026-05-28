class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_count{0};
        int size = nums.size();
        // To achieve true o(n) time and o(1) space as required, lets check how
        // many 0's there are Case 1: at least two 0's
        for (int i = 0; i < size; i++) {
            if (nums[i] == 0) {
                if (++zero_count > 1) {
                    return vector<int>(size, 0);
                }
            }
        }

        vector<int> o(size, 1);

        // First, forward pass
        for (int i = 1; i < size; i++) {
            o[i] = o[i - 1] * nums[i - 1];
        }

        int rightProduct = 1;
        for (int i = size - 1; i >= 0; i--) {
            o[i] *= rightProduct; // Multiply the existing left product by the
                                  // right product
            rightProduct *= nums[i]; // Update the right product
        }

        return o;
    }
};