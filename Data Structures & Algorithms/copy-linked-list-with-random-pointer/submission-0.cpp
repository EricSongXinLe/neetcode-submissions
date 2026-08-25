/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>mp; //from oldNode* to newNode*
        Node* curr = head;
        while(curr){
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        Node* curr2 = mp[head];
        while(curr && curr2){
            Node* next = curr->next;
            Node* random = curr->random;
            curr2->next = mp[next];
            curr2->random = mp[random];
            curr = curr->next;
            curr2 = curr2->next;
        }
        return mp[head];
    }
};
