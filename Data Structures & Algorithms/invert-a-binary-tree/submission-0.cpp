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
    TreeNode* invertTree(TreeNode* root) {
        set<TreeNode*> visited{};
        queue<TreeNode*> toVisit{};
        if (!root) return nullptr;
        toVisit.push(root);
        visited.insert(root);

        while (toVisit.size() != 0) {
            TreeNode* currNode = toVisit.front();
            toVisit.pop();
            // process node
            swap(currNode->left, currNode->right);

            if(currNode->left) toVisit.push(currNode->left);
            if(currNode->right) toVisit.push(currNode->right);
        }
        
        return *visited.begin();

    }
};
