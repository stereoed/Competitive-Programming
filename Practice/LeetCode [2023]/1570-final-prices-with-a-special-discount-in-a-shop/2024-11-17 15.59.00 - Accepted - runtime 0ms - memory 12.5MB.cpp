class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        /* Attempt 1: O(N) space.
        int n = prices.size();
        stack<int> greater{};

        for (int i = 0; i < n; i++){
            while (!greater.empty() && prices[greater.top()] >= prices[i]){
                prices[greater.top()] = prices[greater.top()] - prices[i];
                greater.pop();
            }
            greater.push(i);
        }
        return prices; // Time 0ms, 12.8mb */

        int n = prices.size();
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++) {
                if (prices[j] <= prices[i]) {
                    prices[i] -= prices[j];
                    break;                  
                }
            }
        }
        return prices;
    }
};