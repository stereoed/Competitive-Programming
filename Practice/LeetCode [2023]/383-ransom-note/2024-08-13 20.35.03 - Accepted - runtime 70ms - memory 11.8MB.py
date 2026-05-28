class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        dic = {}
        for i in magazine:
            if i in dic:
                dic[i] += 1
            else:
                dic[i] = 1
        print(dic)
        for i in ransomNote:
            if i not in dic or dic[i] == 0:
                return False
            dic[i] -= 1
            print(dic)
        return True