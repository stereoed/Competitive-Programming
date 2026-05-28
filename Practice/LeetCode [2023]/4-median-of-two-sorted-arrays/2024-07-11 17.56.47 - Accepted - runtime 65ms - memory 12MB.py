import math
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        l1, l2 = len(nums1)-1, len(nums2)-1
        n = float((l1 + l2 + 1.0)/2.0)
        if l1 > l2:
            for x in nums2:
                nums1.append(x)
            nums1.sort()
            return (nums1[int(math.floor(n))] + nums1[int(math.ceil(n))])/2.0
        else:
            for x in nums1:
                nums2.append(x)
            nums2.sort()
            return (nums2[int(math.floor(n))] + nums2[int(math.ceil(n))])/2.0