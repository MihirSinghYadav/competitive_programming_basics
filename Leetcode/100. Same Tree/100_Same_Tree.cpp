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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // If both trees are empty, they are the same.
        if (p == nullptr && q == nullptr)
            return true;
        
        // If one of the trees is empty or their values are different, they are not the same.
        if (p == nullptr || q == nullptr || p->val != q->val)
            return false;

        // Recursively check if the left and right subtrees are the same.
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};

int main()
{
    // Create two binary trees with sample values
    // Tree 1:
    //     1
    //    / \
    //   2   3
    TreeNode *tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    // Tree 2:
    //     1
    //    / \
    //   2   3
    TreeNode *tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    // Create an instance of the Solution class
    Solution solution;

    // Check if the two trees are the same
    bool isSame = solution.isSameTree(tree1, tree2);
    if (isSame)
    {
        cout << "The two binary trees are the same." << endl;
    }
    else
    {
        cout << "The two binary trees are not the same." << endl;
    }

    // Don't forget to free the allocated memory for the trees
    delete tree1;
    delete tree2;

    return 0;
}
