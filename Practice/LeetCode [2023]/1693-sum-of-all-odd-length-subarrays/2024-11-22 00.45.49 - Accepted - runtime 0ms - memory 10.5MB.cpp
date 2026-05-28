class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& nums) {
        int n = nums.size();

        nums[0] *= (n+1) / 2;
        for (int i = 1; i < n; i++){
            nums[i] = nums[i-1] + nums[i]*((((i+1)*(n-i))+1) / 2);
        } 
        return nums.back(); 

        /*
        int n = nums.size();
        int totalSum = 0;

        for (int i = 0; i < n; i++) {

            // Multiply the value by its frequency in odd-length subarrays
            nums[i] *= ((i + 1) * (n - i) + 1) / 2;

            // Accumulate the result in place
            totalSum += nums[i];
        }
        
        return totalSum; */
    }
};
