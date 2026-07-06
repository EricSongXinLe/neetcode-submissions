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
        return dfs(root, INT_MIN);
    }
    int dfs(TreeNode* root, int max){
        if(!root) return 0;
        int curr_val = root->val;
        if(curr_val >= max){
            max = curr_val;
            // good!!
            return dfs(root->left, max) + dfs(root->right, max) + 1;
        }else{
            //not good
            return dfs(root->left, max) + dfs(root->right, max);
        }
    }
};
