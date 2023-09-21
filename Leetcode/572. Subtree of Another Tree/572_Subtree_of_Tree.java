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
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        // If the subRoot is null or the main tree contains the same subtree, return
        // true
        if (subRoot == null || isSameTree(root, subRoot))
            return true;
        // If the main tree is null, return false
        if (root == null)
            return false;
        // Recursively check left and right subtrees for the subRoot
        return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
    }

    private boolean isSameTree(TreeNode p, TreeNode q) {
        // Check if both trees are null, return true
        if (p == null && q == null)
            return true;
        // If one tree is null or the values are different, return false
        if (p == null || q == null || p.val != q.val)
            return false;
        // Recursively check left and right subtrees
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }

    public static void main(String[] args) {
        // Create the main tree:
        // 3
        // / \
        // 4 5
        // / \
        // 1 2
        TreeNode mainTree = new TreeNode(3);
        mainTree.left = new TreeNode(4);
        mainTree.right = new TreeNode(5);
        mainTree.left.left = new TreeNode(1);
        mainTree.left.right = new TreeNode(2);

        // Create the sub-tree:
        // 4
        // / \
        // 1 2
        TreeNode subTree = new TreeNode(4);
        subTree.left = new TreeNode(1);
        subTree.right = new TreeNode(2);

        // Create an instance of the Solution class
        Solution solution = new Solution();

        // Check if the sub-tree is present in the main tree
        boolean isSubtree = solution.isSubtree(mainTree, subTree);

        if (isSubtree) {
            System.out.println("The sub-tree is present in the main tree.");
        } else {
            System.out.println("The sub-tree is not present in the main tree.");
        }
    }
}
