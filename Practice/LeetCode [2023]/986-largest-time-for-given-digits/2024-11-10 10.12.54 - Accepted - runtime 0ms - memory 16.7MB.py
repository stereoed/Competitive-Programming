class Solution:
    def largestTimeFromDigits(self, arr: List[int]) -> str:
        """
        00:00 to 23:59

        """
        answer = ""
        for time in itertools.permutations(arr, 4):
            # print(time)
            h1, h2, m1, m2 = time
            if (h1, h2) < (2, 4) and m1 < 6:
                answer = max(answer, f"{h1}{h2}:{m1}{m2}")
        return answer