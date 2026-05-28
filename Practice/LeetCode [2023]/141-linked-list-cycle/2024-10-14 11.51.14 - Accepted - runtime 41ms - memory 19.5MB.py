
class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        seen = {}
        while head:
            if head.next and head.next in seen: 
                return True
            seen[head] = 1
            head = head.next
        

        return False