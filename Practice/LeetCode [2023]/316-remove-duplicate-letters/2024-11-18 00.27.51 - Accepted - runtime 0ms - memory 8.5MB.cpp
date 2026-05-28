class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> charCount(26, 0);
        vector<bool> inResult(26, false);
        string result = ""; // Acts like a stack

        for (char c : s) {
            charCount[c - 'a']++;
        }

        for (char c : s) {
            charCount[c - 'a']--;
            if (inResult[c - 'a']) continue;

            while (!result.empty() && result.back() > c && charCount[result.back() - 'a'] > 0) {
                inResult[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(c);
            inResult[c - 'a'] = true;
        }
        return result;
    }
};
