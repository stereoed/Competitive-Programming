class Solution(object):
    def findPoisonedDuration(self, timeSeries, duration):
        """
        :type timeSeries: List[int]
        :type duration: int
        :rtype: int
        """
        dur = 0
        for i in range(len(timeSeries)):
            if i+1 >= len(timeSeries):
                return dur + duration
            else:
                dur += min(timeSeries[i+1], timeSeries[i]+duration) - timeSeries[i]

