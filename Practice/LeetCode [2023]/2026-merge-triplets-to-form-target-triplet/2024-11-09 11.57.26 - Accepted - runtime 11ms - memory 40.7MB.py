class Solution(object):
    def mergeTriplets(self, triplets, target):
        """
        :type triplets: List[List[int]]
        :type target: List[int]
        :rtype: bool
        """
        found = set()

        for trip in triplets:
            # Means we cannot use this tripplet
            if trip[0] > target[0] or trip[1] > target[1] or trip[2] > target[2]:
                continue
            # found a valid triplet to use for first value
            if trip[0] == target[0]:
                found.add(0)
            if trip[1] == target[1]:
                found.add(1)
            if trip[2] == target[2]:
                found.add(2)
            if len(found) == 3:
                return True
        return False
            


        