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
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
    int height(TreeNode* root){
        if(!root) return 0;
        int lHeight = height(root->left);
        if(lHeight == -1) return -1;
        int rHeight = height(root->right);
        if(rHeight == -1) return -1;
        if(abs(lHeight - rHeight) > 1) return -1;
        return max(lHeight,rHeight) + 1;
    }
};
