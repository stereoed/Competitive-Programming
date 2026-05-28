class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // Attempt 1: double input array
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> toFind;
        bool twoPass{true};

        for (int j = 0; j < 2; j++){
            for (int i = 0; i < n; i++){
                while (!toFind.empty() && nums[toFind.top()] < nums[i]){
                    result[toFind.top()] = nums[i];
                    toFind.pop();
                }

                if (twoPass){
                    toFind.push(i);
                }
            }
            if (toFind.size() == 1) return result;
            twoPass = false;
        }

        return result;
    }
};

/* NGE I 0ms sol
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> result(n, -1);

        // Map to store the next greater element for each value in nums2
        vector<int> next_greater(10001, -1); // All values are <= 10^4
        stack<int> toFind;

        // Compute next greater elements for nums2
        for (int num : nums2) {
            while (!toFind.empty() && toFind.top() < num) {
                next_greater[toFind.top()] = num; // Assign the next greater element
                toFind.pop();
            }
            toFind.push(num);
        }

        // Map values in nums1 to their next greater element
        for (int i = 0; i < n; ++i) {
            result[i] = next_greater[nums1[i]];
        }

        return result;
    }
};
*/