class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> charCount(26, 0);
        for (char c : s) {
            charCount[c - 'a']++;
        }

        stack<char> resultStack;
        unordered_set<char> inStack;

        for (char c : s) {
            charCount[c - 'a']--;
            if (inStack.count(c)) {
                continue;
            }

            // Pop characters from the stack while they are greater than the
            // current character
            while (!resultStack.empty() && resultStack.top() > c &&
                   charCount[resultStack.top() - 'a'] > 0) {
                inStack.erase(resultStack.top());
                resultStack.pop();
            }

            resultStack.push(c);
            inStack.insert(c);
        }

        string result = "";
        while (!resultStack.empty()) {
            result = resultStack.top() + result;
            resultStack.pop();
        }

        return result;
    }
};