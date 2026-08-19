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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        return divide(lists, 0, lists.size() - 1); 
    }

    ListNode* divide(vector<ListNode*>& lists, int start, int end){
        if(start == end) return lists[start];
        int mid = start + (end - start)/2;
        ListNode* left = divide(lists, start, mid);
        ListNode* right = divide (lists, mid + 1, end);
        ListNode* ptr1 {left};
        ListNode* ptr2 {right};
        ListNode dummy {ListNode()};
        ListNode* ptr {&dummy};
        while(ptr1 != nullptr && ptr2 != nullptr){
            if(ptr1->val < ptr2->val){
                ptr->next = ptr1;
                ptr1 = ptr1->next;
            }
            else {
                ptr->next = ptr2;
                ptr2 = ptr2->next;
            }
            ptr = ptr->next;
        }
        if(ptr1 != nullptr) ptr->next = ptr1;
        if(ptr2 != nullptr) ptr->next = ptr2;
        return dummy.next;
    }
};
