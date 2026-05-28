class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        d = {
            "2":"abc",
            "3":"def",
            "4":"ghi",
            "5":"jkl",
            "6":"mno",
            "7":"pqrs",
            "8":"tuv",
            "9":"wxyz"
        }

        output = []
        aux = []
        if digits:
            digits = digits[::-1]
            for a in d[digits[0]]:
                output += a

            for digit in digits[1:]:
                for a in d[digit]:
                    for o in output:
                        aux += [a+o]
                output = aux
                aux = []
        return output

