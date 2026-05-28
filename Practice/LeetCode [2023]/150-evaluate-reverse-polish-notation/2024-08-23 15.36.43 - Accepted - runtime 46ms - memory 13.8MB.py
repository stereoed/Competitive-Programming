class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = []
        for token in tokens:
            if token == "+":
                n2 = stack.pop()
                n1 = stack.pop()
                stack.append(n1 + n2)
            elif token == "-":
                n2 = stack.pop()
                n1 = stack.pop()
                stack.append(n1-n2)
            elif token == "*":
                n2 = stack.pop()
                n1 = stack.pop()
                stack.append(n1*n2)
            elif token == "/":
                n2 = stack.pop()
                n1 = stack.pop()
                stack.append(int(n1 / n2) if n1 * n2 > 0 else -(-n1 // n2))
            else:
                stack.append(int(token))
        return stack[0]