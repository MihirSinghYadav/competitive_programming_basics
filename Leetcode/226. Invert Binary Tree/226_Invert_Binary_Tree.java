class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public TreeNode invertTree(TreeNode root) {
        // Base case: If the root is null, return null (no need to invert).
        if (root == null) {
            return null;
        }

        // Swap the left and right subtrees of the current node.
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;

        // Recursively invert the left and right subtrees.
        invertTree(root.left);
        invertTree(root.right);

        // Return the root node of the inverted tree.
        return root;
    }

    public static void main(String[] args) {
        // Create a sample binary tree
        //       1
        //      / \
        //     2   3
        //    / \
        //   4   5
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        // Create an instance of the Solution class
        Solution solution = new Solution();

        // Invert the binary tree
        TreeNode invertedRoot = solution.invertTree(root);

        // Print the inverted tree (in-order traversal)
        System.out.println("Inverted Tree:");
        inOrderTraversal(invertedRoot);
    }

    private static void inOrderTraversal(TreeNode node) {
        if (node == null) {
            return;
        }
        // In-order traversal: Visit left, current, right.
        inOrderTraversal(node.left);
        System.out.print(node.val + " ");
        inOrderTraversal(node.right);
    }
}
