class Solution(object):
    def canThreePartsEqualSum(self, arr):
        sum1 =sum(arr)
        if sum1%3!=0:
            return False
        div = sum1/3
        count = 0
        sum2 = 0
        # sum3 =0
        for i in range(len(arr)):
            sum2+=arr[i]
            if sum2 == div:
                sum2=0
                
                count+=1
            

            if count == 3:
                return True
        return False