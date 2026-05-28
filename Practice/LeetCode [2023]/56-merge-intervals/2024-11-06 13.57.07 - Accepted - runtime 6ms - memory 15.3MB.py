class Solution(object):
    def merge(self, intervals):
        intervals.sort(key = lambda x : x[0])
        merge = [intervals[0]]
        for interval in intervals:
            if merge[ - 1][1] < interval[0]:
                merge.append(interval)
            else:
                merge[ - 1][1] = max(merge[ - 1][1], interval[1])
        return merge