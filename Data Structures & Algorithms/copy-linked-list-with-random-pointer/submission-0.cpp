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
        std::unordered_map<Node*, int> uM1 {};
        std::unordered_map<int, int> uM2 {};
        std::unordered_map<int, Node*> uM3 {};
        Node dummy {0};
        Node* newNode {&dummy} ;
        Node* ptr {head};
        int i {};
        while(ptr!= nullptr){
            uM1[ptr] = i; 
            ptr= ptr->next;
            ++i;
        }
        ptr = head;
        i = 0;
        while(ptr != nullptr){
            if(ptr->random == nullptr){
                uM2[i] = -1;
            }
            else{
                uM2[i] = uM1[ptr->random];
            }
            ++i;
            ptr = ptr->next;
        }
        ptr = head;
        i = 0;
        while(ptr != nullptr){
            newNode->next = new Node(ptr->val);
            uM3[i] = newNode->next;
            newNode = newNode->next;
            ++i;
            ptr= ptr->next;
        }
        ptr = dummy.next;
        i = 0;
        while(ptr != nullptr){
            if(uM2[i] != -1)
                ptr->random = uM3[uM2[i]];
            else
                ptr->random = nullptr;
            ptr = ptr->next;
            ++i;
        }
        return dummy.next;


    }
};
