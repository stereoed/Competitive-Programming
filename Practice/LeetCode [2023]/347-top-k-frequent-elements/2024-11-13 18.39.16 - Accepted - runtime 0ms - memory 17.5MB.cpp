class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Option 1: unordered_map into a max_heap (4ms)
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            h;
        for (const auto& pair : m) {
            h.push({pair.second, pair.first});
            if (h.size() > k) {
                h.pop();
            }
        }

        vector<int> o;
        while (!h.empty()) {
            o.push_back(h.top().second);
            h.pop();
        }

        return o;
    }
};