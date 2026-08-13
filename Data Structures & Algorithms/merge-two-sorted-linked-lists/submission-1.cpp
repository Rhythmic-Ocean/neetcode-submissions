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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* myNode {new ListNode()};
        ListNode* head = myNode;
        ListNode* prev {};
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val<= list2->val){
                myNode->val= list1->val;
                list1 = list1->next;
            }
            else{
                myNode->val= list2->val;
                list2 = list2->next;
            }
            prev = myNode;
            myNode->next = new ListNode();
            myNode = myNode->next;
        }
        while(list1 != nullptr){
            myNode->val= list1->val;
            myNode->next = new ListNode();
            prev = myNode;
            myNode = myNode->next;
            list1 = list1->next;
        }
        while(list2 != nullptr){
            myNode->val= list2->val;
            myNode->next = new ListNode();
            prev = myNode;
            myNode = myNode->next;
            list2 = list2->next;
        }
        if(prev == nullptr) return nullptr;
        prev->next = nullptr;
        return head;
    }
};
