class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        k = len(lists)
        
        stack = []
        for i in range(k):
            head = lists[i]
            while head:
                stack.append(head.val)
                head = head.next
        stack.sort()

        pointer = back_pointer = None
        while stack:
            pointer = ListNode(stack.pop())
            if back_pointer:
                pointer.next = back_pointer
            back_pointer = pointer
        return pointer

