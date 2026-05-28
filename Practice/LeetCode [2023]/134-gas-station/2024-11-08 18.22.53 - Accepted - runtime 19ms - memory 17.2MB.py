class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        if sum(cost) > sum(gas):
            return -1

        total, index = 0, 0
        for i in range(len(gas)):
            total += gas[i] - cost[i]
            if total < 0:
                index = i + 1
                total = 0

        return index