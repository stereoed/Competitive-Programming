class Solution(object):
    def maximumUnits(self, boxTypes, truckSize):
        boxes = sorted(boxTypes , key = lambda item: item[1], reverse =True)
        num_boxes = 0
        ans = 0

        n = len(boxes)

        for i in range(n):
            if num_boxes +boxes[i][0] <= truckSize:
                units = boxes[i][0] * boxes[i][1]
                ans += units
                num_boxes += boxes[i][0]
            elif num_boxes <= truckSize:
                while num_boxes != truckSize:
                    ans += boxes[i][1]
                    num_boxes += 1
                
         
        return ans

        