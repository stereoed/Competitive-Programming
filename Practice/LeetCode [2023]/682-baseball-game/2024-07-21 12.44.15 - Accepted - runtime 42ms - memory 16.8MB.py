class Solution:
    def calPoints(self, operations: List[str]) -> int:
        scores = []
        if len(operations) == 0:
            return 0

        for i, c in enumerate(operations):
            if c == "C":
                scores.pop()
            elif c == "D" and i != 0:
                scores.append(scores[-1] * 2)
            elif c == "+" and i != 0:
                scores.append(scores[-1] + scores[-2])
            else:
                scores.append(int(c))
        return sum(scores)

        