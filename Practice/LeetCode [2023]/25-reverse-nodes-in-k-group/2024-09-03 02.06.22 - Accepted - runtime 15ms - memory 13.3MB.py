class Solution(object):
    def reverse_order(self, sp, fp):
        prev = fp.next
        fp.next = None

        pointer = sp

        while pointer:
            print(pointer.val)
            aux = pointer.next
            pointer.next = prev
            prev = pointer
            pointer = aux
        return prev

    def reverseKGroup(self, head, k):
        s_pointer = f_pointer = head

        # Generate k distance between pointers:
        for i in range(k-1):
            f_pointer = f_pointer.next

        # Reverse order between those two nodes
        head = self.reverse_order(s_pointer, f_pointer)

        # Switch places between pointers
        s_pointer, f_pointer = f_pointer, s_pointer

        # Save aux position of last node for later :)
        aux = f_pointer

        while f_pointer:
            # Advance k elements at a time
            for i in range(k):
                s_pointer = s_pointer.next
                f_pointer = f_pointer.next
                if not f_pointer:
                    return head

            # Reverse order between those two
            print("-- DEBUG --")

            # Inject the "reversed" thing into aux.next (the continuation of the previous one)
            aux.next = self.reverse_order(s_pointer, f_pointer)

            # Save aux position of last node for later :)
            s_pointer, f_pointer = f_pointer, s_pointer
            aux = f_pointer
        return head