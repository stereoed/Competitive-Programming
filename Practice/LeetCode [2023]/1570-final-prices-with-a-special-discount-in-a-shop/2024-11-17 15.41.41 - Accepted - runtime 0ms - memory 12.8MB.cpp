class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<pair<int,int>> greater{};

        for (int i = 0; i < n; i++){
            while (!greater.empty() && greater.top().first >= prices[i]){
                prices[greater.top().second] = greater.top().first - prices[i];
                greater.pop();
            }
            greater.push({prices[i], i});
        }

        return prices;

    }
};