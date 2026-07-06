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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(p && p->val > root->val && q && q->val > root->val){
            root = root->right;
            return lowestCommonAncestor(root,p,q);
        }
        else if (p && p->val < root->val && q && q->val < root->val){
            root = root->left;
            return lowestCommonAncestor(root,p,q);
        }
        else return root; //the current one is okay...
    }
};
