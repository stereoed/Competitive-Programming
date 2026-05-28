class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        s1 = set(nums1)
        s2 = set(nums2)
        l1 = len(s1)
        l2 = len(s2)

        result = []
        if l1 > l2:
            for i in s1:
                result.extend([i] * min(nums1.count(i), nums2.count(i)))
        else:
            for i in s2:
                result.extend([i] * min(nums1.count(i), nums2.count(i)))
        return result