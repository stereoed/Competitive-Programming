class Solution(object):

    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """

        def printDaGroup(aux):
            print("Printing", aux)
            if len(aux) == 1:
                return str(aux[0])
            else:
                return str(aux[0]) + "->" + str(aux[-1])

        if not nums:
            return []
        grouped_nums = []
        aux = [nums[0]]
        last = nums[0]
        for i in nums[1:]:
            if i == last + 1:
                aux.append(i)
            elif aux:
                grouped_nums.append(aux)
                aux = [i]
            last = i
        grouped_nums.append(aux)
        print(grouped_nums)

        ans = []
        for i in grouped_nums:
            ans.append(printDaGroup(i))
        return ans