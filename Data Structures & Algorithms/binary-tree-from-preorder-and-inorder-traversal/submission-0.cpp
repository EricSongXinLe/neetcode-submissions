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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            inIdx[inorder[i]] = i;
        }
        return dfs(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    TreeNode* dfs(vector<int>& preorder, int pS, int pE, 
                vector<int>& inorder, int iS, int iE){
            if(pS > pE || iS > iE){return nullptr;}
            int rootVal = preorder[pS];
            int rootInorderIdx = inIdx[rootVal];
            int preLeftLen = rootInorderIdx - iS;
            TreeNode* root = new TreeNode(rootVal);
            root->left = dfs(preorder, pS+1, pS+preLeftLen, inorder, iS, iS+preLeftLen-1);
            root->right = dfs(preorder, pS+preLeftLen+1, pE, inorder, iS+preLeftLen+1, iE);
            return root;
        }
private:
    unordered_map<int,int>inIdx; //inorder val->index
};
