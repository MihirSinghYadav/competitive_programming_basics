#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        // Base case: If the root is null, return null (no need to invert).
        if (root == NULL)
            return NULL;

        // Swap the left and right subtrees of the current node.
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Recursively invert the left and right subtrees.
        invertTree(root->left);
        invertTree(root->right);

        // Return the root node of the inverted tree.
        return root;
    }
};

void printTree(TreeNode *node)
{
    if (node == nullptr)
        return;
    cout << node->val << " ";
    printTree(node->left);
    printTree(node->right);
}

int main()
{
    // Create a binary tree with sample values [4,2,7,1,3,6,9]
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    // Create an instance of the Solution class
    Solution solution;

    // Invert the binary tree
    TreeNode *invertedRoot = solution.invertTree(root);

    // Print the inverted tree
    cout << "Inverted Tree:" << endl;
    printTree(invertedRoot);

    return 0;
}
