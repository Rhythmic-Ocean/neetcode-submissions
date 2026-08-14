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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy (0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        for(int i {}; i <=n; ++i){
            fast = fast->next;
        }
        while(fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* toDel {slow->next};
        slow->next = slow->next->next;
        delete toDel;
        return dummy.next;
    }
};
