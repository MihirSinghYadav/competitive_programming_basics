from typing import Optional
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxDepth_recursiveDFS(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        return 1 + max(
            self.maxDepth_recursiveDFS(root.left),
            self.maxDepth_recursiveDFS(root.right),
        )

    def maxDepth_BFS(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        level = 0
        q = deque([root])
        while q:
            for i in range(len(q)):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            level += 1
        return level

    def maxDepth_IterativeDFS(self, root: Optional[TreeNode]) -> int:
        stack = [[root, 1]]
        result = 0

        while stack:
            node, depth = stack.pop()

            if node:
                result = max(result, depth)
                stack.append([node.left, depth + 1])
                stack.append([node.right, depth + 1])

        return result


# Main function
def main():
    # Create a binary tree with sample values
    #       3
    #      / \
    #     9  20
    #       /  \
    #      15   7
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)

    # Create an instance of the Solution class
    solution = Solution()

    # Calculate and print the maximum depth of the binary tree using Iterative DFS
    max_depth = solution.maxDepth_IterativeDFS(root)
    print("Maximum Depth of Binary Tree (Iterative DFS):", max_depth)

    # Calculate and print the maximum depth of the binary tree using BFS
    max_depth_bfs = solution.maxDepth_BFS(root)
    print("Maximum Depth of Binary Tree (BFS):", max_depth_bfs)

    # Calculate and print the maximum depth of the binary tree using Recursive DFS
    max_depth_recursive = solution.maxDepth_recursiveDFS(root)
    print("Maximum Depth of Binary Tree (Recursive DFS):", max_depth_recursive)


if __name__ == "__main__":
    main()
