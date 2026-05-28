class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int fi = -1, li = -1, mav = nums.front(), miv = nums.back();

        for (int i = 0; i < nums.size(); i++){
            int n = nums[i];
            if (n >= mav) mav = n; else li = i;
        }
        
        for (int i = nums.size() - 1; i > -1; i--){
            int n = nums[i];
            if (n <= miv) miv = n; else fi = i;
        }

        cout << fi << " " << li;
        if (fi == -1 || li == -1) {
            return 0;
        }
        return li - fi + 1;
    }
};