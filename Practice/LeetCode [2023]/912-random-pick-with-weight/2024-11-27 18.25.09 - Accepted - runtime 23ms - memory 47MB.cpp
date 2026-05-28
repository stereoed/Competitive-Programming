class Solution {
public:
    vector<int> p; // Prefix sums array
    Solution(vector<int>& w) {
        p = w; 
        for (int i = 1; i < w.size(); i++) {
            p[i] += p[i - 1];
        }
    }
    
    int pickIndex() {
        int x = p.back();
        int index = rand() % x;
        auto it = upper_bound(p.begin(), p.end(),index);
        return it - p.begin();
    }
};
