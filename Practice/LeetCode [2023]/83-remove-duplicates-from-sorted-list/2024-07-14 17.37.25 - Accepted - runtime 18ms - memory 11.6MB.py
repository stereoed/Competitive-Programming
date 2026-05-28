# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        value = -101
        back_pointer = None
        pointer = head
        while pointer:
            if pointer.val <= value:
                back_pointer.next = pointer.next if pointer.next else None
            else:
                value = pointer.val
                back_pointer = pointer
            pointer = pointer.next if pointer.next else None
        return head