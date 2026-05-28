class Solution(object):
    def combinationSum2(self, candidates, target):
        self.o = []
        self.candidates = sorted(candidates)
        self.target = target
        self.leng = len(self.candidates)
        
        def rec(arr, current_sum, index):
            # Nums are all positive, and so, once we reach the target, we cant go back
            if index == len(self.candidates) or current_sum >= self.target:
                if current_sum == self.target:
                    self.o.append(arr[:])
                return

            # Check if we add the next digit without this one
            i = index + 1
            while i < self.leng and self.candidates[i] == self.candidates[i-1]:
                i += 1
            rec(arr, current_sum, i)

            # Check if we add the next digit with this one
            arr.append(self.candidates[index])
            current_sum += self.candidates[index]
            rec(arr, current_sum, index + 1)
            
            # Pop the array to backtrack
            arr.pop()

        rec([], 0, 0)
        return self.o