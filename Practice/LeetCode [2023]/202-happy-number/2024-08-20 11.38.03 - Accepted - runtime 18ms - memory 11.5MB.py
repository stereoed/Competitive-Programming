class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        cycle=[]
        while n!=1:
            a=0
            for i in str(n):
                a+=int(i)**2
            n=a
            if n==1 or n in cycle:
                break
            cycle.append(n)
        return(n==1)