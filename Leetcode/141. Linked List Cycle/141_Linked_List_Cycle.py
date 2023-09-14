class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        slow, fast = head, head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        return False


# Helper function to create a linked list with a cycle
def create_linked_list_with_cycle(values, pos):
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    cycle_node = None
    for i, val in enumerate(values[1:]):
        current.next = ListNode(val)
        current = current.next
        if i == pos:
            cycle_node = current
    if pos >= 0:
        current.next = cycle_node
    return head


if __name__ == "__main__":
    # Create a sample linked list with a cycle
    values = [1, 2, 3, 4, 5]
    cycle_position = 1  # Position of the node where the cycle begins (0-based index)
    head_with_cycle = create_linked_list_with_cycle(values, cycle_position)

    # Create a Solution object and check for a cycle in the linked list
    solution = Solution()
    has_cycle = solution.hasCycle(head_with_cycle)

    if has_cycle:
        print("The linked list has a cycle.")
    else:
        print("The linked list does not have a cycle.")
