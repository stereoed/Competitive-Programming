class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        left, right, count = 0, k, k
        table = {l:s[0:k+1].count(l) for l in set(s[0:k+1])}

        def increase_value(value):
            if value in table:
                table[value] += 1
            else:
                table[value] = 1

        if k >= len(s):
            return len(s)

        while right < len(s):
            right += 1

            if (right-left) - max(table.values()) > k:
                table[s[left]] -= 1
                left += 1
            else:
                count += 1

            if right == len(s):
                break

            increase_value(s[right])
        return count