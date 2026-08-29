/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) { return dfs(root, subRoot); }

    bool dfs(TreeNode* root, TreeNode* subRoot) {
        // base case for nullptr
        if (root == nullptr) return false;

        // check if currnode is same tree as subroot
        if (isSameTree(root, subRoot)) return true;

        // recursive call
        return dfs(root->left, subRoot) || dfs(root->right, subRoot);
    }

    bool isSameTree(TreeNode* a, TreeNode* b) {
        if (a == nullptr && b == nullptr) {
            return true;
        }

        if ((a != nullptr && b != nullptr) && (a->val == b->val)) {
            return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
        }

        return false;
    }
};
