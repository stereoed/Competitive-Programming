class Solution {
public:
    int pivotInteger(int n) {
        int totalSum = n * (n + 1) / 2, sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
            if (sum == totalSum - sum + i) return i;
        }
        return -1;
    }
};