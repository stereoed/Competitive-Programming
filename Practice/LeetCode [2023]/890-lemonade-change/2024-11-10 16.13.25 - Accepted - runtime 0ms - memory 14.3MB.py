class Solution(object):
    def lemonadeChange(self, bills):
        wallet = {5: 0, 10: 0, 20: 0}
        for bill in bills:
            wallet[bill] += 1
            change = bill - 5
            if change == 5:
                if wallet[5]:
                    wallet[5] -= 1
                else:
                    return False
            elif change == 15:
                if wallet[10] and wallet[5]:
                    wallet[10] -= 1
                    wallet[5] -= 1
                elif wallet[5] > 2:
                    wallet[5] -= 3
                else:
                    return False
        return True
        