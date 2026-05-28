class StockSpanner {
public:
    vector<pair<int, int>> price_history; // To store price and span pairs
    
    StockSpanner() {
        // No need to initialize price_history here, it's already an empty vector
    }
    
    int next(int price) {
        int span = 1; // Span starts with 1 (current day itself)
        int i = price_history.size() - 1;

        // Loop to calculate span by merging spans of smaller or equal prices
        while (i >= 0 && price_history[i].first <= price) {
            span += price_history[i].second; // Add the span of the smaller price
            i -= price_history[i].second;   // Skip the span (jump backward)
        }

        // Add the current price and its span to the history
        price_history.push_back({price, span});

        return span;
    }
};
