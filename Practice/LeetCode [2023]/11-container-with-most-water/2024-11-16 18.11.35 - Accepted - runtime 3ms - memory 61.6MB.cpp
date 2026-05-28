class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int m {0};

        while (left < right){
            if (height[left] > height[right]){
                m = max(m, (right-left)*height[right]);
                right--;
            } else {
                m = max(m, (right-left)*height[left]);
                left++;
            }
        }

        return m;
    }
};