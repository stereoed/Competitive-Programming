class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> start(nums.size(),0);
        vector<int> end(nums.size(),0);
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            start[i]=sum;
        }
        sum=0;
        for(int i=nums.size()-1;i>=0;i--){
            sum+=nums[i];
            end[i]=sum;
        }
        for(int i=0;i<nums.size();i++){
            if(start[i]==end[i]){
                return i;
            }
        }
        return -1;
    }
};