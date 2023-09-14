class Solution {
    public class ListNode {
        int val;
        ListNode next;

        ListNode() {
        };

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    public ListNode reverseList(ListNode head) {
        return rev(head, null);
    }

    public ListNode rev(ListNode node, ListNode pre) {
        if (node == null)
            return pre;
        ListNode temp = node.next;
        node.next = pre;
        return rev(temp, node);
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        ListNode head = s.new ListNode(1, s.new ListNode(2, s.new ListNode(3, s.new ListNode(4, s.new ListNode(5)))));

        // Print the original list
        ListNode temp = head;
        System.out.print("Original List: ");
        while (temp != null) {
            System.out.print(temp.val + " ");
            temp = temp.next;
        }
        System.out.print("\n Reverse List: ");
        ListNode res = s.reverseList(head);
        while (res != null) {
            System.out.print(res.val + " ");
            res = res.next;
        }
    }
}