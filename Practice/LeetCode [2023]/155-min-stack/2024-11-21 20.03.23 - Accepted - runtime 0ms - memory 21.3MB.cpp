class MinStack {
public:
    stack<pair<int, int>> ms;
    int mi = INT_MAX;

    MinStack() {
        // Nothing boy
    }
    
    void push(int val) {
        mi = min(mi, val);
        ms.push({val, mi});
    }
    
    void pop() {
        ms.pop();
        if (!ms.empty()) mi = ms.top().second;
        else mi = INT_MAX;
    }
    
    int top() {
        return ms.top().first;
    }
    
    int getMin() {
        return ms.top().second;
    }
};

