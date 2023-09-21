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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        // If both trees are empty, they are the same.
        if (p == null && q == null)
            return true;

        // If one of the trees is empty or their values are different, they are not the
        // same.
        if (p == null || q == null || p.val != q.val)
            return false;

        // Recursively check if the left and right subtrees are the same.
        return (isSameTree(p.left, q.left) && isSameTree(p.right, q.right));
    }

    public static void main(String[] args) {
        // Create two binary trees with sample values
        // Tree 1:
        //     1
        //    / \
        //   2   3
        TreeNode tree1 = new TreeNode(1);
        tree1.left = new TreeNode(2);
        tree1.right = new TreeNode(3);

        // Tree 2:
        //     1
        //    / \
        //   2   3
        TreeNode tree2 = new TreeNode(1);
        tree2.left = new TreeNode(2);
        tree2.right = new TreeNode(3);

        // Create an instance of the Solution class
        Solution solution = new Solution();

        // Check if the two trees are the same
        boolean isSame = solution.isSameTree(tree1, tree2);
        if (isSame) {
            System.out.println("The two binary trees are the same.");
        } else {
            System.out.println("The two binary trees are not the same.");
        }
    }
}
