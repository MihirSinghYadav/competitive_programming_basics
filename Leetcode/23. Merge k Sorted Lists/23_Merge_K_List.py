from typing import Optional, List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoList(self, list1, list2):
        if not list1:
            return list2
        if not list2:
            return list1

        if list1.val < list2.val:
            list1.next = self.mergeTwoList(list1.next, list2)
            return list1
        else:
            list2.next = self.mergeTwoList(list1, list2.next)
            return list2
    
    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists or len(lists) == 0:
            return None
        
        while len(lists) > 1:
            mergedList = []

            for i in range(0,len(lists),2):
                l1 = lists[i]
                l2 = lists[i+1] if (i+1) < len(lists) else None
                mergedList.append(self.mergeTwoList(l1,l2))
            lists = mergedList
        return lists[0]
            

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
    current  = head
    while current:
        print(current.val, end=" -> ")
        current = current.next
    print("None")

if __name__ == "__main__":
    lists = [[1, 4, 5], [1, 3, 4], [2, 6]]
    
    linked_lists = [create_linked_list(values) for values in lists]
    solution = Solution()
    merged_head = solution.mergeKLists(linked_lists)
    print_linked_list(merged_head)
    