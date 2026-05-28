class Solution(object):
    def minimumCardPickup(self, cards):
        ans = float('inf')
        n = len(cards)
        pos = defaultdict(lambda: -1)
        for i in range(n):
            if pos[cards[i]] != -1:
                ans = min(i - pos[cards[i]] + 1, ans)
            pos[cards[i]] = i
        return ans if ans != float('inf') else -1
        