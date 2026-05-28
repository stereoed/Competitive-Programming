import math
class Solution(object):
    def is_k_a_valid_answer(self, piles, k, h):
        if not k:
            return False

        i = 0
        while i < h and piles:
            popped = piles.pop()
            aux = math.ceil(popped/k)
            i += aux

            if aux == 1:
                i += len(piles)
                return i <= h
        return i <= h and not piles

    def minEatingSpeed(self, piles, h):
        piles.sort()
        k_min = sum(piles) // h
        k_max = piles[-1]
        while k_min < k_max:
            mid = (k_min+k_max)//2
            if self.is_k_a_valid_answer(piles.copy(), mid, h):
                k_max = mid
            else:
                k_min = mid + 1
        return k_min
