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
    void reorderList(ListNode* head) {
                ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow;
        ListNode* curr = mid->next;
        mid->next = nullptr; //important: must cut it before reversing it.
        ListNode* prev = nullptr;
        while(curr != nullptr){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        ListNode* head2 = prev;
        ListNode* curr1 = head; //2 linked lists in parallel.
        ListNode* curr2 = head2;
        while(curr2){ //List 1 must be longer than list 2.
            ListNode* tmp = curr1->next; //backup both next ptrs of curr nodes.
            ListNode* tmp2 = curr2->next;
            curr1->next = curr2; //rewire next pointers
            curr2->next = tmp;
            curr1 = tmp; //advance both curr
            curr2 = tmp2;
        }
    }
};
