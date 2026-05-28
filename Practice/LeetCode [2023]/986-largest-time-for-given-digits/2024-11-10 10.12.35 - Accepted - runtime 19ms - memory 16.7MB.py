class Solution:
    def largestTimeFromDigits(self, A: List[int]) -> str:
        if min(A) > 3: return '' # early terminate if not possible
        A.sort()
        
        for h in range(23, -1, -1):
            for m in range(59, -1, -1):
                h1,h2 = h//10, h%10
                m1,m2 = m//10, m%10
                
                t = [h1,h2,m1,m2]
                ts = sorted(t)
                
                if ts == A:
                    return "{}{}:{}{}".format(h1,h2,m1,m2)
                
        return ''