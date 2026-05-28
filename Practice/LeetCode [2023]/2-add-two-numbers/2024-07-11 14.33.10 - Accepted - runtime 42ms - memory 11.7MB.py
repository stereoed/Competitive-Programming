# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        num1, num2 = "",""
        while l1 != None:
            print(l1.val)
            num1+=str(l1.val)
            l1 = l1.next
        while l2 != None:
            num2 += str(l2.val)
            l2 = l2.next
        a = str(int(num1[::-1]) + int(num2[::-1]))
        aux = ListNode(int(a[0]), None)
        for e in range(1, len(a)):
            l3 = ListNode(int(a[e]), aux)
            aux = l3
        return aux