class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        
        operators = set('+-*/')
        incompleteOperations = []

        while len(tokens):
            if len(tokens) == 1 and tokens[0] not in operators:
                return int(tokens[0])
            a = tokens.pop(0)
            if a in operators and incompleteOperations:
                b = int(incompleteOperations.pop(1))
                c = int(incompleteOperations.pop(0))
                if a == "/":
                    a = "//"
                    if (b < 0 or c < 0) and (b > 0 or c > 0):
                        b = -b
                        result = str(-eval(str(b) + a + str(c)))
                        tokens = [result] + tokens
                        continue
                result = str(eval(str(b) + a + str(c)))
                tokens = [result] + tokens
            else:
                incompleteOperations = [a] + incompleteOperations
        return 0



        