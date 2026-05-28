class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<bool> space(right - left + 1, false); // Represent the range [left, right] as a boolean array
        
        for (const vector<int>& v : ranges) {
            for (int i = max(v[0], left); i <= min(v[1], right); i++) {
                space[i - left] = true; // Mark the position as covered
            }
        }
        
        for (bool b : space) {
            if (!b) return false; // If any position is not covered, return false
        }
        
        return true; // All positions are covered
    }
};