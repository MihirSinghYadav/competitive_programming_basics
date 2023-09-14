class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev, curr = None, head

        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        return prev


def create_linked_list(values):
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    for val in values[1:]:
        current.next = ListNode(val)
        current = current.next
    return head


def print_linked_list(head):
    current = head
    while current:
        print(current.val, end=" -> ")
        current = current.next
    print("None")


if __name__ == "__main__":
    values = [1, 2, 3, 4, 5]
    head = create_linked_list(values)

    print("Original Linked List: ")
    print_linked_list(head)

    solution = Solution()
    reversed_head = solution.reverseList(head)

    print("Reversed Linked List: ")
    print_linked_list(reversed_head)
