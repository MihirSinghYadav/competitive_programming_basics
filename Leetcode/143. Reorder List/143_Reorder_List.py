from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        # find middle
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # reverse second half
        second = slow.next
        slow.next = None  # Break the list into two halves
        prev = None
        while second:
            temp = second.next
            second.next = prev
            prev = second
            second = temp

        # merge two halves
        first, second = head, prev
        while second:
            temp1, temp2 = first.next, second.next
            first.next = second
            second.next = temp1
            first, second = temp1, temp2


class Main:
    def main(self):
        # Create a sample linked list
        # Example: 1 -> 2 -> 3 -> 4 -> 5
        head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))

        # Create an instance of the Solution class
        solution = Solution()

        # Call the reorderList method
        solution.reorderList(head)

        # Print the reordered linked list
        current = head
        while current:
            print(current.val, end=" -> ")
            current = current.next
        print("None")


if __name__ == "__main__":
    Main().main()
