/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* ptr {head};
        while(ptr != nullptr){
            Node* clone = new Node(ptr->val);
            clone->next = ptr->next;
            ptr->next = clone;
            ptr = clone->next;
        }
        ptr = head;
        while(ptr != nullptr){
            if(ptr->random != nullptr){
                ptr->next->random  = ptr->random->next;
            }
                ptr = ptr->next->next;
        }
        Node * clone_head {head->next};
        Node * ptr2 {clone_head};
        ptr = head;
        while(ptr != nullptr && ptr2->next != nullptr){
            ptr->next = ptr->next->next;
            ptr2->next = ptr2->next->next;
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }
        return clone_head;
    }
};
