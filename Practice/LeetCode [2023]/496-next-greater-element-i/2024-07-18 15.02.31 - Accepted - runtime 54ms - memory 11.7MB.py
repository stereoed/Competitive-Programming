class Solution(object):
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        ans = []
        for i in nums1:
            flag = False
            print(i)
            for j in range(nums2.index(i)+1, len(nums2)):
                if nums2[j] > i:
                    ans.append(nums2[j])
                    flag = True
                    break
            if not flag:
                ans.append(-1)
        return ans