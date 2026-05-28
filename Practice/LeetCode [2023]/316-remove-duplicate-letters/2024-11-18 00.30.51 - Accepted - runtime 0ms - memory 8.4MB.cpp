class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> charCount(26, 0);
        vector<bool> inResult(26, false);
        string result = ""; // Acts like a stack

        for (char c : s) {
            charCount[c - 'a']++;
        }

        result.reserve(26); // El largo maximo es 26, se hace esto para que no sea taxante en la memoria el agregar y quitar
        for (char c : s) {
            charCount[c - 'a']--;
            if (inResult[c - 'a'])
                continue;

            while (!result.empty() && result.back() > c) {
                if (charCount[result.back() - 'a'] == 0)
                    break;
                inResult[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(c);
            inResult[c - 'a'] = true;
        }
        return result;
    }
};
