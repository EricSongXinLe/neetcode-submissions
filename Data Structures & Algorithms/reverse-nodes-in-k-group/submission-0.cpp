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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;
        while(true){
            ListNode* kth = findNextK(groupPrev, k);
            if(kth == nullptr){
                break;
            } //do nothing
            ListNode* nextGroupStart = kth->next;
            
            ListNode* prev = nextGroupStart;
            ListNode* curr = groupPrev->next;

            while(curr != nextGroupStart){
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            ListNode* oldGroupStart = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = oldGroupStart;
        }
        return dummy.next;
    }
private:
    ListNode* findNextK(ListNode* curr, int k){
        while(curr && k > 0){
            curr = curr->next;
            k--;
        }
        return curr;
    }
};
