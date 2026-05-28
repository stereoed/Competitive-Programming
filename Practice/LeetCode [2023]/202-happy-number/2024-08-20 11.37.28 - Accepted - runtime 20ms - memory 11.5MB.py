class Solution(object):
    visited = set()
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        self.visited = set()
        def search(n):
            a = list(str(n))
            sum = 0
            for i in a:
                sum += int(i)**2
            if sum == 1:
                return True
            else:
                if sum in self.visited:
                    return False
                self.visited.add(sum)
                return search(sum)
        return search(n)
            

            

        