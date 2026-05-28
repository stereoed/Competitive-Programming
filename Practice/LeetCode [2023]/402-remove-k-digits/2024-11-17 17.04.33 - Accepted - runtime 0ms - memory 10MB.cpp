class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) return "0";
        string result = "";

        for (char c : num) {
            // Remove digits from result if they are larger than the current digit
            while (!result.empty() && result.back() > c && k > 0) {
                result.pop_back();
                k--;
            }
            result.push_back(c);
        }

        // Remove remaining digits if k > 0
        while (k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }

        // Remove leading zeroes
        size_t pos = result.find_first_not_of('0');
        result = (pos == string::npos) ? "0" : result.substr(pos);

        return result;
    }
};
