class Solution(object):
    def partitionLabels(self, s):
        last_occurrence = {char:i for i, char in enumerate(s)}
        start = 0
        end = 0
        result = []
        for i, char in enumerate(s):
            if last_occurrence[char] > end:
                end = last_occurrence[char]
            if i == end:
                result.append(end - start + 1)
                start = i + 1
        return result

