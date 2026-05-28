class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """       
        o = []
        for i in range(1, n+1):
            a = ""
            if not i % 3:
                a += "Fizz"
            if not i % 5:
                a += "Buzz"
            if i % 3 and i % 5:
                a = str(i)
            o.append(a)
        return o