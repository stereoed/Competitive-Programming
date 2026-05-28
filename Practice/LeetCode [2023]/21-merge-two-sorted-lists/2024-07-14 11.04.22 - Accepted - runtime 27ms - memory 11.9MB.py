def recHeadLinkedListMerger(list1, list2):
        # Check if a list is null
        if not list1:
            return list2
        elif not list2:
            return list1

        valueList1 = list1.val
        valueList2 = list2.val
        if valueList1 < valueList2:
            list3 = list1
            list1 = list1.next if list1.next else None
        else:
            list3 = list2
            list2 = list2.next if list2.next else None
        list3.next = recHeadLinkedListMerger(list1, list2)
        return list3
        
class Solution(object):

    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        # Check if a list is null
        if not list1:
            return list2
        elif not list2:
            return list1

        valueList1 = list1.val
        valueList2 = list2.val
        if valueList1 < valueList2:
            list3 = list1
            list1 = list1.next
        else:
            list3 = list2
            list2 = list2.next
        list3.next = recHeadLinkedListMerger(list1, list2)
        return list3