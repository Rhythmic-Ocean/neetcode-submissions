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
        ListNode* ptr {head};
        int num {};
        int count {};
        while(ptr != nullptr ){
            ptr = ptr->next;
            num ++;
        }
        num--;
        ptr = head;
        if(num - n + 1< 0) return head;
        if(num - n  + 1== 0) return head->next;
        std::cout << num << std::endl;
        while(count < num - n){
            ptr = ptr->next;
            ++count;
        }
        ptr->next = ptr->next->next;
        return head;
    }
};
