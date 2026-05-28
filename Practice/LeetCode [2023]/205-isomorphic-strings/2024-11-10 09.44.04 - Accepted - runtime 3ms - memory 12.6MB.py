class Solution(object):
    def isIsomorphic(self, s, t):
        map = {}
        for i in range(len(s)):
            if s[i] in map:
                if map[s[i]] != t[i]:
                    return False
            else:
                if t[i] in map.values():
                    return False
                map[s[i]] = t[i]
        return True
