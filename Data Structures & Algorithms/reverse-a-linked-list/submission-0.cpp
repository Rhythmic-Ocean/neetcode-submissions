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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return {};
        ListNode* t {head};
        if(head->next==nullptr) return t;
        ListNode * q {head->next};
        if(head->next->next == nullptr){
            q->next = t;
            t->next = nullptr;
            return q;
        }
        head = head->next->next;
        q->next = t;
        t->next = nullptr;
        while(head->next != nullptr){
            t = q;
            q = head;
            head = head->next;
            q->next = t;
        }
        head->next = q;
        return head;
    }
};
