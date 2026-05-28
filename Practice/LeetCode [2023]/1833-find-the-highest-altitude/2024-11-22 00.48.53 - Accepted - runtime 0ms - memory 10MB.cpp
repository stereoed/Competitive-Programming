class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0, o = 0;
        for (const int g : gain) {
            o = max(o, sum);
            sum += g;
        }
        o = max(o, sum);
        return o;
    }
};