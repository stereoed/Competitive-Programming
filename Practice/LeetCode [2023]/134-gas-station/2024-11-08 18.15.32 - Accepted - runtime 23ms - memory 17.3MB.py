class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        if sum(gas) < sum(cost):
            return -1
        
        total_gain = 0
        current_gain = 0
        start_index = 0
        
        for i in range(len(gas)):
            net_gain = gas[i] - cost[i]
            total_gain += net_gain
            current_gain += net_gain
            
            if current_gain < 0:
                start_index = i + 1
                current_gain = 0

        return start_index if total_gain >= 0 else -1

        