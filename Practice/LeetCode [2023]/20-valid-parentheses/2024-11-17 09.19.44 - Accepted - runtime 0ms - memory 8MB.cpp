class Solution {
public:
    unordered_map<char, char> l{{')', '('}, {'}', '{'}, {']', '['}};

    bool isValid(string s) {
        if (s.empty()) return true;
        if (l.count(s.front()) || !l.count(s.back())) return false;

        // O(n) approach, no edgecases
        stack<char> past{};

        for (char c : s) {
            auto it = l.find(c);
            if (it != l.end()) {
                if (past.empty() || it->second != past.top()) return false; 
                past.pop();
            } else {
                past.push(c);
            }
        }
        return past.empty();
    }
};