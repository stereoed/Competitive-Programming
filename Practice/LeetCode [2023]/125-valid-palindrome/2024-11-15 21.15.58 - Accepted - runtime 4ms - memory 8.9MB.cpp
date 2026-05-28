class Solution {
public:
    bool isPalindrome(string s) {
        auto left = s.begin();
        auto right = s.end() - 1; // Correct `right` initialization (s.end()
                                  // points one past the last character)

        while (left < right) {
            // Move left pointer to the next alphanumeric character
            while (left < right && !isalnum(*left)) {
                left++;
            }
            // Move right pointer to the previous alphanumeric character
            while (left < right && !isalnum(*right)) {
                right--;
            }

            if (left >= right) { // Re-check condition after skipping non-alphanumerics
                break;
            }

            // Compare characters case-insensitively
            if (tolower(*left) != tolower(*right)) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
