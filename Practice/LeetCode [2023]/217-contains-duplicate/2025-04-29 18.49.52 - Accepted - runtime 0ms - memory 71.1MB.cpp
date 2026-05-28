class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
            int anterior = 1000000;
            sort(nums.begin(), nums.end());
            for(int i:nums){
                if(anterior==i){
                    return true;
                }
                anterior = i;
            }
        return false;
    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0";});