class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /* 34 ms
        vector<int> o(temperatures.size(), 0);
        stack<pair<int, int>> history; // Store {temperature, index}

        for (int i = 0; i < temperatures.size(); i++) {
            while (!history.empty() && history.top().first < temperatures[i]) {
                int prevIndex = history.top().second;
                o[prevIndex] = i - prevIndex;
                history.pop();
            }
            history.push({temperatures[i], i});
        }
        return o; */

        /* Attempt 2: separate stacks for indeces and temps -> 28 ms: integers
        are faster to handle vector<int> o(temperatures.size(), 0); stack<int>
        tempStack; // Stack for temperatures stack<int> indexStack; // Stack for
        indices

        for (int i = 0; i < temperatures.size(); i++) {
            while (!tempStack.empty() && tempStack.top() < temperatures[i]) {
                tempStack.pop();
                int prevIndex = indexStack.top();
                indexStack.pop();
                o[prevIndex] = i - prevIndex;
            }
            tempStack.push(temperatures[i]);
            indexStack.push(i);
        }
        return o; */

        // Attempt 3: just work with indices
        vector<int> o(temperatures.size(), 0);
        stack<int> indexStack;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!indexStack.empty() && temperatures[indexStack.top()] < temperatures[i]) {
                int prevIndex = indexStack.top();
                indexStack.pop();
                o[prevIndex] = i - prevIndex;
            }
            indexStack.push(i);
        }
        return o;
    }
};
