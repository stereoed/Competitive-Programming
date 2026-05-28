# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        dummy = ListNode(0, head)
        p_current = head
        p_back = dummy

        for i in range(n-1):
            p_current = p_current.next
        while p_current.next:
            p_current = p_current.next
            p_back = p_back.next
        p_back.next = p_back.next.next
        return dummy.next
        