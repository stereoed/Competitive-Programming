class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int result = 0;

        while(left < right){
            if (height[left] < height[right]){
                if (height[left] < left_max) {
                    result += left_max - height[left];
                } else {
                    left_max = height[left];
                }
                left++;
            } else {
                if (height[right] < right_max) {
                    result += right_max - height[right];
                } else {
                    right_max = height[right];
                }
                right--;
            }
        }
        return result;
    }
};
