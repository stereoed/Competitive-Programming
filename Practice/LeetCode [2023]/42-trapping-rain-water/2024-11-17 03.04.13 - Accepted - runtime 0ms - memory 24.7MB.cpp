class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int result = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                // Update left_max and calculate water trapped on left
                if (height[left] >= left_max) {
                    left_max = height[left]; // Update left_max
                } else {
                    result += left_max - height[left]; // Water trapped
                }
                left++; // Move left pointer
            } else {
                // Update right_max and calculate water trapped on right
                if (height[right] >= right_max) {
                    right_max = height[right]; // Update right_max
                } else {
                    result += right_max - height[right]; // Water trapped
                }
                right--; // Move right pointer
            }
        }

        return result;
    }
};
