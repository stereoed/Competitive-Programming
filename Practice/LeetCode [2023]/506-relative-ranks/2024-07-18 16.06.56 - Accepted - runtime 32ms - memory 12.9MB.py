class Solution(object):
    def findRelativeRanks(self, score):
        """
        :type score: List[int]
        :rtype: List[str]
        """
        hashMap = {n:i for i,n in enumerate(score)}
        n = len(score)
        output = [0] * n
        score.sort()
        output[hashMap.get(score[-1])] = "Gold Medal"
        if n > 1:
            output[hashMap.get(score[-2])] = "Silver Medal"
            if n > 2:
                output[hashMap.get(score[-3])] = "Bronze Medal"
        for i in range(-len(score), -3):
            output[hashMap.get(score[i])] = str(-i)
        return output