class Solution(object):
    def merge(self, intervals):
        intervals.sort(key=lambda x: x[0])
        
        merged = [intervals[0]]
        for interval in intervals:
            if merged[-1][1] < interval[0]:
                # No overlap, add current interval to merged
                merged.append(interval)
            else:
                # Overlap, so merge with the last interval in merged
                merged[-1][1] = max(merged[-1][1], interval[1])
        return merged