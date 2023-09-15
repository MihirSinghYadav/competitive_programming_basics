class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int size = lists.length;
        int interval = 1;
        while (interval < size) {
            for (int i = 0; i < size - interval; i += 2 * interval) {
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        return size > 0 ? lists[0] : null;
    }

    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null)
            return list2;
        if (list2 == null)
            return list1;

        if (list1.val < list2.val) {
            list1.next = mergeTwoLists(list1.next, list2);
            return list1;
        } else {
            list2.next = mergeTwoLists(list1, list2.next);
            return list2;
        }
    }

    public static void main(String[] args) {
        // Create linked lists for testing
        ListNode list1 = new ListNode(1, new ListNode(4, new ListNode(5)));
        ListNode list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
        ListNode list3 = new ListNode(2, new ListNode(6));

        // Create an array of linked lists
        ListNode[] lists = { list1, list2, list3 };

        // Create a Solution object and merge the linked lists
        Solution solution = new Solution();
        ListNode mergedList = solution.mergeKLists(lists);

        // Print the merged linked list
        while (mergedList != null) {
            System.out.print(mergedList.val + " -> ");
            mergedList = mergedList.next;
        }
        System.out.println("null");
    }
}