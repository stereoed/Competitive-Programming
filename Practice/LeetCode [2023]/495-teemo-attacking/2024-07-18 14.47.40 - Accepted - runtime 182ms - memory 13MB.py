class Solution(object):
    def findPoisonedDuration(self, timeSeries, duration):
        """
        :type timeSeries: List[int]
        :type duration: int
        :rtype: int
        """
        dur = 0
        l = len(timeSeries)
        for i in range(l):
            if i+1 >= l:
                dur += duration
                break
            dur += min(timeSeries[i+1], timeSeries[i]+duration) - timeSeries[i]
        return dur

