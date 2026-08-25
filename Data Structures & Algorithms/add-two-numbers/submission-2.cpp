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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* c1 = l1;
        ListNode* c2 = l2;
        ListNode* res = &dummy;
        int carry =0;
        while(c1 || c2){
            int v1 = 0;
            int v2 = 0;
            if(c1){
                v1 = c1->val;
                c1 = c1->next;
            }
            if(c2){
                v2 = c2->val;
                c2 = c2->next;
            }
            int sum = carry+v1+v2;
            if(sum >= 10){
                carry = 1;
                sum = sum % 10;
            }else{
                carry = 0;
            }
            res->next = new ListNode(sum);
            res = res->next;
        }
        if(carry == 1){
            res->next = new ListNode(1);
        }
        return dummy.next;
    }
};
