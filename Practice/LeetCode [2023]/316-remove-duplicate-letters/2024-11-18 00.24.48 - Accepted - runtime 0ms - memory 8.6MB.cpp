class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> charCount(26, 0);
        for (char c : s) {
            charCount[c - 'a']++;
        }

        stack<char> resultStack;
        vector<bool> inStack(26, false);

        for (char c : s) {
            charCount[c - 'a']--;
            if (inStack[c - 'a']) continue;

            // Pop characters from the stack while they are greater than the
            // current character
            while (!resultStack.empty() && resultStack.top() > c &&
                   charCount[resultStack.top() - 'a'] > 0) {
                inStack[resultStack.top() - 'a'] = false;
                resultStack.pop();
            }

            resultStack.push(c);
            inStack[c - 'a'] = true;
        }

        string result = "";
        while (!resultStack.empty()) {
            result = resultStack.top() + result;
            resultStack.pop();
        }

        return result;
    }
};