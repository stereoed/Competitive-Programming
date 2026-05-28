# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        #Initial
        if not head:
            return

        prev = None
        pointer = head

        while pointer:
            aux = pointer.next
            pointer.next = prev
            prev = pointer
            pointer = aux
        return prev
