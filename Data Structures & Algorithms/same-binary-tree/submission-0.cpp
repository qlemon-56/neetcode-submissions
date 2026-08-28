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
    bool isSameTree(TreeNode* p, TreeNode* q) { return dfs(p) == dfs(q); }

    vector<int> dfs(TreeNode* root) {
        set<TreeNode*> visited{};
        vector<int> store{};
        stack<TreeNode*> myS{};
        myS.push(root);

        while (myS.size() != 0) {
            // set up current node

            TreeNode* currNode = myS.top();
            myS.pop();

            if (!currNode) {
                store.push_back(-101);
                continue;
            }
            // process current node
            if (visited.count(currNode) == 0) {
                visited.insert(currNode);
                store.push_back(currNode->val);
            }

            // loop through neighbours
            myS.push(currNode->left);
            myS.push(currNode->right);
        }

        return store;
    }
};
