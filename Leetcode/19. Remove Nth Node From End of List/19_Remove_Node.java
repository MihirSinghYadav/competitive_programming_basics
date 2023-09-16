class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode fast = head, slow = head;

        for (int i = 0; i < n; i++)
            fast = fast.next;

        if (fast == null)
            fast = head.next;

        while (fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }
        slow.next = slow.next.next;
        return head;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        ListNode current = head;
        int[] values = { 2, 3, 4, 5 };
        for (int val : values) {
            current.next = new ListNode(val);
            current = current.next;
        }
        Solution solution = new Solution();
        int n = 2;
        ListNode updatedHead = solution.removeNthFromEnd(head, n);
        current = updatedHead;
        while (current != null) {
            System.out.print(current.val + " -> ");
            current = current.next;
        }
        System.out.println("null");
    }
}