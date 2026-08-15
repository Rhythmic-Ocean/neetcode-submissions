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
        std::unordered_map<Node *, Node *> uM {};
        Node dummy {0};
        Node* ptr = head;
        Node* clone = &dummy;
        while(ptr != nullptr){
            clone->next = new Node(ptr->val);
            uM[ptr] = clone->next;
            ptr = ptr->next;
            clone = clone->next;
        }    
        ptr = head;
        clone = &dummy;
        while(ptr != nullptr){
            if(ptr->random == nullptr){
                uM[ptr]->random = nullptr;
            }
            else{
                uM[ptr]->random  = uM[ptr->random];
            }
            ptr = ptr->next;
        }
        return dummy.next;
    }
};
