class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        if( n < 2 ) return false;
        unordered_map<int, int> m; // sum, index
        m[0] = 0;
        nums[0] %= k;
        int sum = nums[0];
        for( int i = 1; i < n; ++i ) {
            nums[i] %= k;
            sum += nums[i];
            // 
        }
        cout << sum;
        if( sum < k ) {
            return false;
        }
        if( sum == k ) {
            return true;
        }
        sum = 0;
        for( int i = 0; i < n; ++i ) {
            sum += nums[i];
            int diff = sum-k;
            sum %= k;
            if( m.contains(diff) || m.contains(sum) && (i-m[sum] > 1) ) {
                return true;
            }
            m[sum] = i;
        }
        return false;
    }
};