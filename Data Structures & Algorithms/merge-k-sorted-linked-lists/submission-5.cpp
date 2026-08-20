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
        if(lists.empty())  return nullptr;
        vector<ListNode*> mergedLists {};
        while(lists.size() > 1){
            mergedLists.clear();
            for(int i {}; i < lists.size(); i+=2){
                ListNode* l1 = lists[i];
                ListNode* l2 = (i+1 >= lists.size())?nullptr: lists[i+1];
                mergedLists.push_back(mergeList(l1, l2));
            }
            lists = mergedLists;
        }
        return lists[0];
    }
    ListNode* mergeList(ListNode* l1, ListNode* l2){
        ListNode dummy = ListNode();
        ListNode* ptr {&dummy};
        while(l1 && l2){
            if(l1->val< l2->val){
                ptr->next = l1;
                l1 = l1->next;
            }
            else{
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }
        if(l1){
            ptr->next = l1;
        }
        else if(l2){
            ptr->next = l2;
        }
        return dummy.next;
    }
};
