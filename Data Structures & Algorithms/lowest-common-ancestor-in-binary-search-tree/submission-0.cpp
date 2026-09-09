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
    vector<TreeNode*> temp {};
    vector<vector<TreeNode*>> res {};

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        dfs(root, p->val);
        dfs(root, q->val);
        
        auto c = res[0];
        auto d = res[1];

        auto it = c.begin();
        auto it2 = d.begin();
        
        while (it < c.end() && it2 < d.end()) {
            if (*it != *it2) break;
            it++;
            it2++;
        }

        return *prev(it);
    }

    void dfs(TreeNode* root, int& target) {
        // base condition
        if (!root) return;

        // process node
        temp.push_back(root);
        if (root->val == target) {
            res.push_back(temp);
            temp = {};
            return;
        }
        // loop through neighbours
        if (target > root->val && root->right) dfs(root->right, target);
        if (target < root->val && root->left) dfs(root->left, target); 

    }
};
