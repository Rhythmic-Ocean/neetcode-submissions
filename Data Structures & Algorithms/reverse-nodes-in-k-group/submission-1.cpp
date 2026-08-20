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
        if(!head) return head;
        ListNode dummy {};
        ListNode* prev_top {&dummy};
        ListNode* top {head};
        while (true){
            ListNode* ptr {top};
            int i {};
            while(ptr != nullptr && i < k){
                ptr = ptr->next;
                ++i;
            }
            if(i != k){
                prev_top->next = top;
                break;
            }
            i = 0;
            ListNode* prev {top};
            ListNode* cur {prev->next};
            prev->next = nullptr;
            while(cur != nullptr && i < k-1){
                ListNode* nxt = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nxt;
                ++i;
            }
            prev_top->next = prev;
            prev_top = top;
            top = cur;
        }
        return dummy.next;
    }
};
