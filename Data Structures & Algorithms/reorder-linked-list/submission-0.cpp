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
        if(!head || !head->next || !head->next->next) return;
       ListNode* fast {head};
       ListNode* slow {head};
       while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
       }
       ListNode* l1 {head};
       ListNode*l2 {slow->next};
       slow->next = nullptr;
       ListNode* prev{nullptr};
       ListNode* cur {l2};
       while(cur != nullptr){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
       }
       l2 = prev;
       while(l1 != nullptr && l2 != nullptr){
            ListNode* temp = l1->next;
            l1->next = l2;
            l1 = temp;
            temp = l2->next;
            l2->next = l1;
            l2 = temp;
       }
       return;
    }
};
