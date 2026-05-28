class Solution(object):
    def partitionLabels(self, s):
        #Step 1: Create a dictionary to store the last occurrence of each character
        last_occurrence = {char:i for i, char in enumerate(s)}
        
        # Step 2: Initialize pointers and result list
        start = 0
        end = 0
        result = []
        
        # Step 3: Traverse the string to find partitions
        for i, char in enumerate(s):
            # Update the end to the farthest last occurrence of the current character
            end = max(end, last_occurrence[char])
            
            # When the current index reaches the end, we have found a partition
            if i == end:
                # Append the size of the partition to the result list
                result.append(end - start + 1)
                # Move the start to the next position
                start = i + 1
        
        return result

