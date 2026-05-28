class Solution(object):
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        hashMap = {n:i for i,n in enumerate(nums1)}
        stack = []
        res = [-1] * len(nums1)
        for i in range(len(nums2)):
            value = nums2[i]
            while stack:
                if stack[-1] < value:
                    res[hashMap.get(stack.pop())] = value
                else:
                    break
            if (value in hashMap) and (not stack or value < stack[-1]):
                stack.append(value)
        return(res)