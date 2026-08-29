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
    int maxSum {INT_MIN};
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }

    int dfs(TreeNode* currNode) {
        // check null node
        if (!currNode) return 0;

        // process kids
        int left = dfs(currNode->left);
        int right = dfs(currNode->right);

        int leftGain = max(left, 0);
        int rightGain = max(right, 0);

        maxSum = max(currNode->val + leftGain+rightGain, maxSum);

        // return info for parent
        return currNode->val + max(leftGain, rightGain);
    }
};
