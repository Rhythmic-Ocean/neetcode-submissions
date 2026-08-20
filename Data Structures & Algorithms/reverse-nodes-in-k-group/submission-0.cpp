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
        if(!head || !head->next) return head;
        ListNode dummy {};
        ListNode* prev_top {&dummy};
        ListNode* top {head};
        while(top){
            ListNode* prev {top};
            ListNode* cur {prev->next};
            prev->next = nullptr;
            int i {};
            while(i < k - 1 && cur != nullptr){
                ListNode* nxt = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nxt;
                ++i;
            }
            if(i < k - 1){
                cur = prev->next;
                prev->next = nullptr;
                while(cur != nullptr){
                    ListNode* nxt = cur->next;
                    cur->next = prev;
                    prev = cur;
                    cur = nxt; 
                }
            }
            prev_top->next = prev;
            std::cout << prev_top->next->val << std::endl;
            if(cur == nullptr){
                break;
            }
            prev_top = top;
            top = cur;
        }
        return dummy.next;
    }
};
