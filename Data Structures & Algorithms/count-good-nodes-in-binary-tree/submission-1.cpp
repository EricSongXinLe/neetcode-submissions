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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        return dfs(root, root->val);
    }
    int dfs(TreeNode* root, int curr_max){
        if(!root)return 0;
        if(root->val >= curr_max){
            curr_max = root->val;
            return dfs(root->left, curr_max) + dfs(root->right, curr_max) + 1;
        }else{
            return dfs(root->left, curr_max) + dfs(root->right, curr_max);
        }
    }
};
