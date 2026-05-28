class Solution(object):
    dic = {1:1, 2:2, 3:3}
    def climbStairs(self, n):
        if n in self.dic:
            return self.dic[n]
        
        self.dic[n] = self.climbStairs(n-1) + self.climbStairs(n-2)
        return self.dic[n]
        