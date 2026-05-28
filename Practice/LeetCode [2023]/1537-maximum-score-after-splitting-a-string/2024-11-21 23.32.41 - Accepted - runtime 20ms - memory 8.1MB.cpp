class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), o = 0;
        vector<int> prefixSum(n + 1);
        for (int i = 1; i < n + 1; i++){
            prefixSum[i] = prefixSum[i - 1] + (s[i - 1] - '0');
            cout << prefixSum[i] << " ";
        }

        for (int i = n - 1; i >= 1; i--){
            o = max(o, prefixSum[n] - 2*prefixSum[i] + i);
        }
        return o;
    }
};