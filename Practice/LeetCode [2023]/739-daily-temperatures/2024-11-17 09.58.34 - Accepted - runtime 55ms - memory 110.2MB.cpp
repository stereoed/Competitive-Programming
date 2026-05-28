class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> o(temperatures.size(), 0);
        stack<pair<int, int>> history;

        for (int i = 0; i < temperatures.size(); i++){
            while (!history.empty() && history.top().first < temperatures[i]){
                o[history.top().second] = i - history.top().second;
                history.pop();
            }
            history.push({temperatures[i], i});
        }
        return o;
    }
};