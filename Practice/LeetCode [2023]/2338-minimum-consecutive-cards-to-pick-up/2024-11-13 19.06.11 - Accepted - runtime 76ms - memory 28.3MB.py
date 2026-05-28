class Solution(object):
    def minimumCardPickup(self, cards):
        """
        :type cards: List[int]
        :rtype: int
        """
        last_index = {}
        smallest = float('inf')
        for i, card in enumerate(cards):
            if card in last_index:
                smallest = min(smallest, i - last_index[card] + 1)
            last_index[card] = i

        return -1 if smallest == float('inf') else smallest