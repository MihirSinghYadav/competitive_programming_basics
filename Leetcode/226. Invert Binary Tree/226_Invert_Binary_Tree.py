from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None

        temp = root.left
        root.left = root.right
        root.right = temp

        self.invertTree(root.left)
        self.invertTree(root.right)

        return root


def main():
    # Create a sample binary tree
    #       1
    #      / \
    #     2   3
    #    / \
    #   4   5
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)

    # Create an instance of the Solution class
    solution = Solution()

    # Invert the binary tree
    inverted_root = solution.invertTree(root)

    # Print the inverted tree (in-order traversal)
    def in_order_traversal(node):
        if not node:
            return
        in_order_traversal(node.left)
        print(node.val, end=" ")
        in_order_traversal(node.right)

    print("Inverted Tree:")
    in_order_traversal(inverted_root)


if __name__ == "__main__":
    main()
