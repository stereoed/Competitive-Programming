class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<bool> used (101, false);
        int count = 0;

        for (const vector<int>& v : nums){
            for (int i = v[0]; i <= v[1]; i++){
                if (!used[i]){
                    count ++;
                    used[i] = true;
                }
            }
        }
        
        return count;
    }
};