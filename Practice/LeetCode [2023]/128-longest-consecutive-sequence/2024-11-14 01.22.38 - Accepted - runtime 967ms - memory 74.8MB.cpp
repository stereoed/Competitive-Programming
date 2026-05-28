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

        // Optimal O(N) solution
        // Idea: keep an unordered_set
        if (nums.empty()){
            return 0;
        }

        unordered_set<int> s;
        for (int n : nums) {
            s.insert(n);
        }

        int m{0}, c{1};
        for (int n : nums) {
            if (s.count(n-1)){
                continue;
            }

            while (s.count(++n)){
                c++;
            }

            if (c > m) {
                m = c;
            }
            c = 1;
        }

        return m;
    }
};