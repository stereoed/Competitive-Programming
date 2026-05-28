class Solution(object):
    def carFleet(self, target, position, speed):
        """
        :type target: int
        :type position: List[int]
        :type speed: List[int]
        :rtype: int
        """

        fleet_num = len(position) + 1
        timeToArrive = {position[i]:(float(target-position[i])/speed[i] if speed[i] != 0 else 999999) for i in range(len(position))}
        position.sort()
        maxi = timeToArrive[position[-1]]
        for p in position[::-1]:
            if timeToArrive[p] <= maxi:
                fleet_num -= 1
                continue
            maxi = timeToArrive[p]

        return fleet_num