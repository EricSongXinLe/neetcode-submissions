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

class Codec {
public:
    void serial(TreeNode* root, string& s){
        if(!root){
            s += "#,";
            return;
        }
        s += to_string(root->val) + ",";
        serial(root->left, s);
        serial(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serial(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        queue<string>q;
        string curr;
        while(getline(ss, curr, ',')){
            q.push(curr);
        }
        return deserial(q);
    }
    TreeNode* deserial(queue<string>& q){
        if(q.empty()) return nullptr;
        string curr = q.front();
        q.pop();
        if(curr == "#"){
            return nullptr;
        }
        int val = stoi(curr);
        TreeNode* node = new TreeNode(val);
        node->left = deserial(q);
        node->right = deserial(q);
        return node;
    }
};
