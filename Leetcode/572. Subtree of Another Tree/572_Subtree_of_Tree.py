from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not subRoot:
            return True
        if not root:
            return False
        if self.sameTree(root, subRoot):
            return True
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)

    def sameTree(self, s, t):
        if not s and not t:
            return True
        if s and t and s.val == t.val:
            return self.sameTree(s.left, t.left) and self.sameTree(s.right, t.right)
        return False


# Create the main function to test the isSubtree method
def main():
    # Create the main tree:
    #     3
    #    / \
    #   4   5
    #  / \
    # 1   2
    mainTree = TreeNode(3)
    mainTree.left = TreeNode(4)
    mainTree.right = TreeNode(5)
    mainTree.left.left = TreeNode(1)
    mainTree.left.right = TreeNode(2)

    # Create the sub-tree:
    #   4
    #  / \
    # 1   2
    subTree = TreeNode(4)
    subTree.left = TreeNode(1)
    subTree.right = TreeNode(2)

    # Create an instance of the Solution class
    solution = Solution()

    # Check if the sub-tree is present in the main tree
    is_subtree = solution.isSubtree(mainTree, subTree)

    if is_subtree:
        print("The sub-tree is present in the main tree.")
    else:
        print("The sub-tree is not present in the main tree.")


if __name__ == "__main__":
    main()
