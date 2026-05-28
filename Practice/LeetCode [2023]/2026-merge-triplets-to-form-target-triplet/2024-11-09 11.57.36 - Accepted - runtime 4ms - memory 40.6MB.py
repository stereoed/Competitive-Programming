class Solution(object):
    def mergeTriplets(self, triplets, target):
        flag = [False, False, False]
        for triplet in triplets:
            for i in range(3):
                if triplet[i] > target[i]:
                    break
            else:
                r = True
                for i in range(3):
                    if triplet[i] == target[i]:
                        flag[i] = True 
                    elif not flag[i]:
                        r = False
                if r:
                    return True

        return False
                
        