class Solution:
    def insert(self, intervals, newInterval):
        x0, y0 = newInterval
        i = 0
        n = len(intervals)
        
        # Traverse through intervals in place
        while i < n:
            x, y = intervals[i]
            
            # Case 1: New interval is before the current interval
            if y0 < x:
                intervals.insert(i, [x0, y0])  # Insert newInterval in its correct position
                return intervals
            
            # Case 2: New interval is after the current interval (no overlap)
            elif y < x0:
                i += 1
            
            # Case 3: There is overlap; merge intervals
            else:
                x0 = min(x0, x)
                y0 = max(y0, y)
                intervals.pop(i)  # Remove the current interval after merging
                n -= 1  # Adjust the length since we removed an interval
        
        # If newInterval is greater than all existing intervals, append at the end
        intervals.append([x0, y0])
        return intervals

# Testing the optimized function
obj = Solution()
print(obj.insert([[3, 5], [12, 15]], [6, 6]))  # Expected output: [[3, 5], [6, 6], [12, 15]]
