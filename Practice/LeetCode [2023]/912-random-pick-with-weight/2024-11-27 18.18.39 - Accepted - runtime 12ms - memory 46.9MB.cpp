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
        int weight = rand() % p.back(); // Random value in range [0, sum of weights - 1]
        int left = 0, right = p.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2; // Prevent overflow
            if (p[mid] > weight) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
