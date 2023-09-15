from typing import Optional, List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummy = ListNode()
        tail = dummy

        while list1 and list2:
            if list1.val < list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next

        if list1:
            tail.next = list1
        else:
            tail.next = list2

        return dummy.next


# main function
if __name__ == "__main__":
    list1 = [1, 2, 4]
    list2 = [1, 3, 4]

    # Create linked lists
    head1 = ListNode(list1[0])
    current1 = head1
    for val in list1[1:]:
        current1.next = ListNode(val)
        current1 = current1.next

    head2 = ListNode(list2[0])
    current2 = head2
    for val in list2[1:]:
        current2.next = ListNode(val)
        current2 = current2.next

    # Call the function to merge the lists
    solution = Solution()
    merged_head = solution.mergeTwoLists(head1, head2)

    # Print the merged list
    current = merged_head
    while current:
        print(current.val, end=" -> ")
        current = current.next
    print("None")
