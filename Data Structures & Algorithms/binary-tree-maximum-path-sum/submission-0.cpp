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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
    int dfs(TreeNode* root, int& res){
        if(!root)return 0;
        int lSum = max(0, dfs(root->left, res));
        int rSum = max(0, dfs(root->right, res));
        res = max(res, lSum+rSum+root->val);
        return max(lSum, rSum) + root->val;
    }
};
