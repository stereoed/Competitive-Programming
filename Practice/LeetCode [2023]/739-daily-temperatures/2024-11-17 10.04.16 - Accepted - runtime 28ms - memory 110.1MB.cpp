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

        // Attempt 2: separate stacks for indeces and temps
        vector<int> o(temperatures.size(), 0);
        stack<int> tempStack; // Stack for temperatures
        stack<int> indexStack; // Stack for indices

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
        return o;
    }
};
