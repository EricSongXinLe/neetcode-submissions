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
        ListNode* curr = head;
        ListNode* curr2x = head;
        while(curr && curr2x && curr2x->next){
            curr= curr->next;
            curr2x = curr2x->next->next;
        }
        ListNode* mid = curr; //last of part 1.
        ListNode* secondHalf = mid->next; //first of part two
        mid->next = nullptr; //cut the two.
        ListNode* p2 = reverse(secondHalf);
        //now merge head & revSecondHalf alternatively
        ListNode* p1 = head;
        while(p1 && p2){
            ListNode* p1n = p1->next;
            ListNode* p2n = p2->next;
            p1->next = p2;
            p2->next = p1n;
            p1 = p1n;
            p2 = p2n;
        }
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
};
