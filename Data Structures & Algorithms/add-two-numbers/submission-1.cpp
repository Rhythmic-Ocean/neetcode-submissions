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
        int carry {};
        ListNode dummy {};
        ListNode* ptr {&dummy};
        while(l1 != nullptr && l2 != nullptr){
            int value = l1->val + l2->val + carry;
            if(value <= 9){
                carry = 0;
            }
            else{
                carry = 1;
                value = value - 10;
            }
            ptr->next = new ListNode(value);
            ptr = ptr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr){
            int value =  l1->val+ carry;
            if(value <= 9){
                carry = 0;
            }
            else{
                carry = 1;
                value = value - 10;
            }
            ptr->next = new ListNode(value);
            ptr = ptr->next;
            l1 = l1->next;
        }
        while(l2 != nullptr){
            int value =  l2->val + carry;
            if(value <= 9){
                carry = 0;
            }
            else{
                carry = 1;
                value = value - 10;
            }
            ptr->next = new ListNode(value);
            ptr = ptr->next;
            l2 = l2->next;
    }
    if(carry != 0){
        ptr->next = new ListNode(carry);
    }
    return dummy.next;
    }
};
