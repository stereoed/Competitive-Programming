class Solution(object):
    def lemonadeChange(self, bills):
        wallet = {5: 0, 10: 0, 20: 0}
        for bill in bills:
            wallet[bill] += 1
            change = bill - 5
            if change:
                for candidate_bill in [20, 10, 5]:
                    if candidate_bill <= change:
                        amount = min(change // candidate_bill, wallet[candidate_bill])
                        change -= candidate_bill * amount
                        wallet[candidate_bill] -= amount
            if change:
                return False
        return True
        