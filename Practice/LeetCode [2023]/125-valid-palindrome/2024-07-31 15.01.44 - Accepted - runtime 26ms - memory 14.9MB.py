class Solution(object):
    def isPalindrome(self, s):
        a=s.upper()
        c=s[::-1].upper()
        b= re.sub(r'[^A-Za-z0-9]', '', a)
        print(b)
        d= re.sub(r'[^A-Za-z0-9]', '', c)
        print(d)
        if(b==d):
            return True
        return False