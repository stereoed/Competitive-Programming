class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        dictio = {}
        for s in strs:
            a = {}
            for i in s:
                if i in a:
                    a[i] += 1
                else:
                    a[i] = 1
            dictio[s] = a

        o = []
        for i in strs:
            flag = True
            for n in o:
                if dictio[n[0]] == dictio[i]:
                    n.append(i)
                    flag = False
            if flag:
                o.append([i])
        return o
