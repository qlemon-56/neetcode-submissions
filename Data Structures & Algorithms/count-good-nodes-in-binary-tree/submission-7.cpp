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

    int _goodNodes {0};
    multiset<int> maxPath {};
    int goodNodes(TreeNode* root) {
        dfs(root);
        return _goodNodes;
    }

    void dfs(TreeNode* root) {

        // check null
        if (!root) return;
        

        // process node
        if (maxPath.size() != 0) {
            if (root->val >= *prev(maxPath.end())) _goodNodes++;
        } else _goodNodes++;
        maxPath.insert(root->val);

        // loop through neighbours
        if (root->left) dfs(root->left);
        if (root->right) dfs(root->right);
        maxPath.erase(maxPath.find(root->val));
    }
};
