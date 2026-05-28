class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        # Step 1: Sort intervals by their end times
        intervals.sort(key=lambda x: x[1])
        
        # Initialize last_end to the end of the first interval
        last_end = intervals[0][1]
        removals = 0
        
        # Step 2: Iterate through intervals starting from the second one
        for i in range(1, len(intervals)):
            # If the current interval starts before last_end, it overlaps
            if intervals[i][0] < last_end:
                removals += 1  # Count this interval as a removal
            else:
                # No overlap, update last_end to the end of the current interval
                last_end = intervals[i][1]
        
        return removals
