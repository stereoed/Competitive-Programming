class Solution(object):
    seen = {1: ["()"],
            2: ["(())", "()()"]}
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        def buildup(n):
            # Check if seen
            if n in self.seen:
                return self.seen[n]
            
            # Backtracking recursion
            arr = set(buildup(n-1))

            # Algorithm for creating left parentheses
            aux_arr = set()
            for snapshot in arr:
                valid = True
                for index in range(len(snapshot)):
                    if valid or snapshot[index] != '(':
                        aux_arr.add(snapshot[:index+1] + '(' + snapshot[index+1:])
                    valid = snapshot[index] != '('
                    
            aux_arr_close = set()
            for candidate in aux_arr:
                open_parenthesis = 1

                for index in range(len(candidate) - 1, 0, -1):
                    if open_parenthesis > 0:
                        aux_arr_close.add(candidate[:index + 1] + ')' + candidate[index + 1:])
                        open_parenthesis -= 1
                    open_parenthesis += -1 if candidate[index] == ')' else 0
            arr = list(aux_arr_close)
            
            # Saving for later
            self.seen[n] = arr
            return arr

        return buildup(n)

