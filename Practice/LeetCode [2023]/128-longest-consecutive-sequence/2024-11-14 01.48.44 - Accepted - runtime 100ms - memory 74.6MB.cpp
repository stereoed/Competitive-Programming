class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /* Intuitive O(NlogN)
        if (nums.empty()){
            return 0;
        }

        priority_queue<int> h;
        for (int n : nums) {
            h.push(n);
        }

        int m{0}, c{1}, last{h.top()};
        h.pop();

        while (!h.empty()) {
            if (h.top() == last){
                h.pop();
                continue;
            }

            if (h.top() == last - 1) {
                c++;
            } else {
                if (c > m) {
                    m = c;
                }
                c = 1;
            }
            last = h.top();
            h.pop();
        }
        if (c > m) {
            m = c;
        }
        return m;
        */

        /* Optimal O(N) solution -> This solution is somehow slower :(
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        if (nums.size() < 2) {
            return nums.size();
        }

        unordered_set<int> s(nums.begin(), nums.end());

        int m{0}, c{1};
        for (int n : nums) {
            if (s.count(n - 1)) {
                continue;
            }

            while (s.find(++n) != s.end()){
                c++;
                s.erase(n);
            }

            m = max(m, c);
            c = 1;
        }

        return m;
        */

        // Using maps, could be faster than last, its 2 fucking am rn :)
        // Edge case: if nums has fewer than 2 elements, return its size
        if (nums.size() < 2) {
            return nums.size();
        }

        // Initialize an unordered_map to store each number and a "used" status
        unordered_map<int, bool> num_map;
        for (int n : nums) {
            num_map[n] = false;  // Initially, all numbers are marked as "not used"
        }

        int maxLength = 0;

        for (int n : nums) {
            // Only start a new sequence if `n` hasn't been used and `n-1` is not in the map
            if (!num_map[n] && !num_map.count(n - 1)) {
                int l = 1;

                // Expand to the right
                while (num_map.count(++n) && !num_map[n]) {
                    num_map[n] = true;  // Mark as used
                    l++;
                }

                maxLength = max(maxLength, l);  // Update the max length if needed
            }
        }

        return maxLength;

    }
};