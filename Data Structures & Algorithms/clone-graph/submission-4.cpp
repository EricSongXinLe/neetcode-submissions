/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*>visited;
        return dfs(node, visited);
    }
    Node* dfs(Node* node, unordered_map<Node*, Node*>& visited){
        if(!node) return nullptr;
        if(visited.count(node)){
            return visited[node];
        }
        Node* curr = new Node(node->val);
        visited[node] = curr;
        for(Node* neighbor : node->neighbors){
            curr->neighbors.push_back(dfs(neighbor, visited));
        }
        return curr;
    }
};
