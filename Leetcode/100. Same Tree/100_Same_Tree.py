from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        # If both trees are empty, they are the same.
        if not p and not q:
            return True

        # If one of the trees is empty or their values are different, they are not the same.
        if not p or not q or p.val != q.val:
            return False

        # Recursively check if the left and right subtrees are the same.
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)


def main():
    # Create two binary trees with sample values
    # Tree 1:
    #     1
    #    / \
    #   2   3
    tree1 = TreeNode(1)
    tree1.left = TreeNode(2)
    tree1.right = TreeNode(3)

    # Tree 2:
    #     1
    #    / \
    #   2   3
    tree2 = TreeNode(1)
    tree2.left = TreeNode(2)
    tree2.right = TreeNode(3)

    # Create an instance of the Solution class
    solution = Solution()

    # Check if the two trees are the same
    is_same = solution.isSameTree(tree1, tree2)
    if is_same:
        print("The two binary trees are the same.")
    else:
        print("The two binary trees are not the same.")


if __name__ == "__main__":
    main()
