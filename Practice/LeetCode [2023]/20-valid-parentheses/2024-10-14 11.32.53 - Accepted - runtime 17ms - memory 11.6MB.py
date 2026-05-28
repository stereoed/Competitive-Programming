class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if (not s.count('(') == s.count(')')) or (not s.count('{') == s.count('}')) or (not s.count('[') == s.count(']')):
            return False
        stack = []
        for i in s:
            if i == ')' and stack and stack.pop() == '(':
                continue
            elif i == '}' and stack and stack.pop() == '{':
                continue
            elif i == ']' and stack and stack.pop() == '[':
                continue
            elif i == '(' or i == '{' or i == '[':
                stack.append(i)
            else:
                return False
        return True