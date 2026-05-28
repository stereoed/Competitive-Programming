class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        o = [0]*len(temperatures)
        stack = []
        for i in range(len(temperatures)):
            temp = temperatures[i]
            while stack:
                if stack[-1][0] < temp:
                    aux = stack.pop(-1)
                    o[aux[1]] = i-aux[1]
                else:
                    break
            if not stack or stack[-1][0] >= temp:
                stack.append([temp, i])
        return o