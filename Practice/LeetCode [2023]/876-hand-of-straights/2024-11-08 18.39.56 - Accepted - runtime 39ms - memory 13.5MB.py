from collections import Counter

class Solution(object):
    def isNStraightHand(self, hand, groupSize):
        if len(hand) % groupSize != 0:
            return False
        
        # Step 1: Count the frequency of each card
        card_count = Counter(hand)
        
        # Step 2: Sort the unique cards to process them in order
        unique_cards = sorted(card_count)
        
        # Step 3: Try to form groups starting from the smallest card
        for card in unique_cards:
            if card_count[card] > 0:  # Only process if there are cards left
                count = card_count[card]  # The number of groups that need to start with this card
                
                # Try to form a group of `groupSize` consecutive cards
                for i in range(1, groupSize):
                    if card_count[card + i] < count:
                        return False
                    card_count[card + i] -= count  # Deduct the count for the group
        
        return True
