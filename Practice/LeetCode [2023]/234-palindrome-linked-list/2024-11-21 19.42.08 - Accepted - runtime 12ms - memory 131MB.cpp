class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> s;
        while (head){
            s.push_back(head->val);
            head = head->next;
        }

        int left = 0, right = s.size() - 1;
        while (left < right){
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};