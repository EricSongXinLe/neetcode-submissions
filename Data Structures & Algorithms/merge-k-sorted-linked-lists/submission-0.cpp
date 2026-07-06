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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for(int i = 0; i < lists.size(); ++i){
            ListNode* curr = lists[i];
            if(curr){
                pq.push(curr); //insert the first non-empty nodes into the pq
            }
        }
        ListNode* curr = dummy;
        while(!pq.empty()){
            ListNode* smallest_node = pq.top();
            pq.pop();
            curr->next = smallest_node;
            if(smallest_node->next){
                pq.push(smallest_node->next);
            }
            curr = curr->next;
        }
        ListNode* ans = dummy->next;
        delete(dummy);
        return ans;
    }
private:
    struct Compare{
    bool operator()(ListNode* a, ListNode* b){
            if(a->val > b->val) return true;
            return false;
        }
    };
};
