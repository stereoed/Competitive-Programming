class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        o = 0
        pA, recA = headA, [headA]
        pB, recB = headB, [headB]

        while pA.next:
            pA = pA.next
            recA.append(pA)
        while pB.next:
            pB = pB.next
            recB.append(pB)

        ot = None
        while o < min(len(recA), len(recB)) and recA[-1-o] == recB[-1-o]:
            ot = recA[-1-o]
            o += 1
        return ot
        