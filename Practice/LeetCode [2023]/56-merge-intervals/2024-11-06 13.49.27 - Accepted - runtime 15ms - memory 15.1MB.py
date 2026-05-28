class Solution(object):
    def merge(self, intervals):
        intervals.sort(key=lambda x: x[0])
        i, n = 0, len(intervals)
        while i < n - 1:
            if intervals[i][1] >= intervals[i+1][0]:
                intervals[i][1] = max(intervals[i][1], intervals[i + 1][1])
                intervals.pop(i + 1)
                n -= 1
                continue
            i += 1
        return intervals