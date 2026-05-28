class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> greater{};

        for (int i = 0; i < n; i++){
            while (!greater.empty() && prices[greater.top()] >= prices[i]){
                prices[greater.top()] = prices[greater.top()] - prices[i];
                greater.pop();
            }
            greater.push(i);
        }
        return prices;
    }
    // Time 0ms, 12.8mb
};