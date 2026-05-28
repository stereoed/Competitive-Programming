class Solution(object):
    def nextGreatestLetter(self, letters, target):
        """
        :type letters: List[str]
        :type target: str
        :rtype: str
        """
        l = set(letters)
        lowest = None
        for i in l:
            if i > target:
                if lowest == None or i < lowest:
                    lowest = i
        return lowest if lowest else letters[0]