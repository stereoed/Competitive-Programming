class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        s = set(nums)
        if len(s) == k:
            return s

        dictio = dict()
        for n in s:
            dictio[n] = nums.count(n)

        goal = sorted(list(dictio.values()), reverse=True)[k-1]
        o = []
        for i in s:
            if dictio[i] >= goal:
                o.append(i)
        return o
