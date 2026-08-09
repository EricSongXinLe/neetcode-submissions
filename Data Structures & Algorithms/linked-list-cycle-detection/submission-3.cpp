/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(!head) return false;
        if(head && (!(head->next))) return false;
        ListNode* curr = head;
        ListNode* curr2x = head;
        while(curr && curr2x && curr2x->next){
            curr = curr->next;
            curr2x = curr2x->next->next;
            if(curr == curr2x) return true;
        }
        return false;
    }
};
