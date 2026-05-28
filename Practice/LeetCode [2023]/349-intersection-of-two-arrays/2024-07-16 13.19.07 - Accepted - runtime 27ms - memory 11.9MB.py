class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        nums1 = set(nums1)
        nums2 = set(nums2)

        l1 = len(nums1)
        l2 = len(nums2)

        result = []
        if l1 > l2:
            for i in nums2:
                if (nums1.__contains__(i)):
                    result.append(i)
        else:
            for i in nums1:
                if (nums2.__contains__(i)):
                    result.append(i)
        return result