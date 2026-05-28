class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        l1 = len(nums1)
        l2 = len(nums2)

        result = []
        if l1 > l2:
            for i in nums2:
                if i in nums1:
                    result.append(i)
                    nums1.remove(i)
        else:
            for i in nums1:
                if i in nums2:
                    result.append(i)
                    nums2.remove(i)
        return result