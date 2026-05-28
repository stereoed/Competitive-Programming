class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> o(temperatures.size(), 0);
        stack<pair<int, int>> history; // Store {temperature, index}

        for (int i = 0; i < temperatures.size(); i++) {
            // Compare current temperature with the top of the stack
            while (!history.empty() && history.top().first < temperatures[i]) {
                // Update the result for the index stored at the top
                int prevIndex = history.top().second;
                o[prevIndex] = i - prevIndex;
                history.pop();
            }
            // Push the current temperature and index onto the stack
            history.push({temperatures[i], i});
        }
        return o;
    }
};
