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
    vector<int> rightSideView(TreeNode* root) {
        // set up queue
        if (!root) return {};

        queue<TreeNode*> q{};
        q.push(root);
    
        vector<int> res {}, temp {};

        while (!q.empty()) {

            int limit = q.size();
            for (int i = 0; i < limit; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                temp.push_back(curr->val);          
            }
            if (!temp.empty()) res.push_back(temp.back()); else break;
            temp = {};
        }
        return res;
    }
};
