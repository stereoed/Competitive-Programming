class Solution {
public:
    unordered_map<char, char> l{{')', '('}, {'}', '{'}, {']', '['}};

    bool isValid(string s) {
        // O(n) approach, no edgecases
        stack<char> past{};

        for (char c : s) {
            if (l.count(c)) {
                if (past.empty() || l[c] != past.top()) {
                    return false;
                }
                past.pop();
            } else {
                past.push(c);
            }
        }
        return past.empty();
    }
};