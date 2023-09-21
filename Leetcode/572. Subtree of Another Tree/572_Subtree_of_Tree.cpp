#include <iostream>
using namespace std;

// Definition for a binary tree node.
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
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        // If the main tree is null, return true
        if (root == NULL)
            return false;

        // Check if the subRoot is the same as the main tree or present in the left or right subtrees
        if (isSameTree(root, subRoot))
            return true;

        // Recursively check the left and right subtrees for the subRoot
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    bool isSameTree(TreeNode *root, TreeNode *subRoot)
    {
        // Check if both trees are null, return true
        if (root == NULL && subRoot == NULL)
            return true;

        // If one tree is null or the values are different, return false
        if (root == NULL || subRoot == NULL)
            return false;

        if (root->val != subRoot->val)
            return false;

        // Recursively check the left and right subtrees
        return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
    }
};

int main()
{
    // Create the main tree:
    //     3
    //    / \
    //   4   5
    //  / \
    // 1   2
    TreeNode *mainTree = new TreeNode(3);
    mainTree->left = new TreeNode(4);
    mainTree->right = new TreeNode(5);
    mainTree->left->left = new TreeNode(1);
    mainTree->left->right = new TreeNode(2);

    // Create the sub-tree:
    //   4
    //  / \
    // 1   2
    TreeNode *subTree = new TreeNode(4);
    subTree->left = new TreeNode(1);
    subTree->right = new TreeNode(2);

    // Create an instance of the Solution class
    Solution solution;

    // Check if the sub-tree is present in the main tree
    bool isSubtree = solution.isSubtree(mainTree, subTree);

    if (isSubtree)
    {
        cout << "The sub-tree is present in the main tree." << endl;
    }
    else
    {
        cout << "The sub-tree is not present in the main tree." << endl;
    }

    // Clean up the memory (optional)
    delete mainTree;
    delete subTree;

    return 0;
}
