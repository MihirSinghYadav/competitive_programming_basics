from typing import Optional, List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        slow = dummy
        fast = head

        while n > 0 and fast:
            fast = fast.next
            n -= 1

        while fast:
            slow = slow.next
            fast = fast.next

        slow.next = slow.next.next
        return dummy.next


if __name__ == "__main__":
    head = ListNode(1)
    current = head
    values = [2, 3, 4, 5]
    for val in values:
        current.next = ListNode(val)
        current = current.next

    solution = Solution()

    n = 2
    updated_head = solution.removeNthFromEnd(head, n)

    current = updated_head
    while current:
        print(current.val, end=" -> ")
        current = current.next
    print("None")
