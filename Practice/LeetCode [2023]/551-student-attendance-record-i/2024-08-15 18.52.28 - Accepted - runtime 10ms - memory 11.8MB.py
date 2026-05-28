class Solution(object):
    def checkRecord(self, s):
        """
        :type s: str
        :rtype: bool
        """
        consL = 0
        A = 0
        for n in s:
            if n == "L":
                consL += 1
                if consL == 3:
                    return False
                continue
            consL = 0  
            if n == "A":
                A += 1
                if A == 2:
                    return False
        return True
        