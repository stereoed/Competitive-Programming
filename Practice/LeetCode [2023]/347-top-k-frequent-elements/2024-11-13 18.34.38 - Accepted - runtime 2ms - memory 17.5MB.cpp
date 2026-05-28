class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Option 1: unordered_map into a max_heap (4ms)
        unordered_map<int, int> m;
        for (int n : nums){
            m[n]++;
        }

        priority_queue<pair<int, int>> h;

        for (const auto& pair : m) {
            h.push({pair.second, pair.first});
        }

        vector<int> o;
        for (int i = 0; i < k; i++){
            o.push_back(h.top().second);
            h.pop();
        }

        return o;
    }
};