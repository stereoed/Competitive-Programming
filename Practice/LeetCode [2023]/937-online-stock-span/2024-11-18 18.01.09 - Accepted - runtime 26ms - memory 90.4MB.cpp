class StockSpanner {
public:
    stack<pair<int, int>> price_history;
    StockSpanner() {
        // No need to initialize price_history here, it's already an empty vector
    }
    
    int next(int price) {
        int span = 1; 
        while (!price_history.empty() && price_history.top().first <= price) {
            span += price_history.top().second;
            price_history.pop();
        }
        price_history.push({price, span});

        return span;
    }
};
