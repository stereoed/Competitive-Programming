class Solution(object):
    keyboard = {
        "2": "abc",
        "3": "def",
        "4": "ghi",
        "5": "jkl",
        "6": "mno",
        "7": "pqrs",
        "8": "tuv",
        "9": "wxyz"
    }

    def letterCombinations(self, digits):
        n = len(digits)
        o = []

        if not n:
            return []
        
        def dfs(index, path):
            if index == n:
                o.append(path)
                return

            for letter in self.keyboard[digits[index]]:
                path += letter
                dfs(index + 1, path)
                path = path[:-1]
                
        dfs(0, "")
        return o
