class Solution(object):
    def checkInclusion(self, s1, s2):
        dic = {}
        cur = {}
        l1 = len(s1)
        l2 = len(s2)

        if l1 > l2:
            return False

        # Count letters
        for i in range(l1):
            letter = s1[i]
            if letter in dic:
                dic[letter] += 1
            else:
                dic[letter] = 1

        # Define window
        left = 0
        right = l1-1

        # Count initial letters in window
        for i in range(right):
            letter = s2[i]
            if letter in cur:
                cur[letter] += 1
            else:
                cur[letter] = 1

        # Initiate window
        while right < l2:
            # Add most recent letter
            letter = s2[right]
            if letter in cur:
                cur[letter] += 1
            else:
                cur[letter] = 1

            # Check condition
            if cur == dic:
                return True

            # Remove oldest letter from dic
            letter = s2[left]
            cur[letter] -= 1
            if not cur[letter]:
                cur.pop(letter)

            # Update counters
            left += 1
            right += 1