class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int n = nums.size(), third = INT_MIN;
        if (n < 3) return false;

        for (int i = n - 1; i > -1; i--){
            int num = nums[i];
            if (num < third) return true;
            while (!s.empty() && s.top() < num){
                third = s.top();
                s.pop();
            }
            
            s.push(num);
        }

        return false;
    }
};