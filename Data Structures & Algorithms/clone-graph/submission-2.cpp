/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<int, Node*> ex_nodes {};
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        Node* new_node = new Node(node->val);
        ex_nodes[node->val] = new_node;
       for(auto* n: node->neighbors){
            new_node->neighbors.push_back(cloneNode(n));
       }
       return new_node;
    }

    Node* cloneNode(Node* current){
        Node* new_node = new Node(current->val);
        ex_nodes[new_node->val] = new_node;
        for(auto* n: current->neighbors){
            if(ex_nodes[n->val] == nullptr){
                new_node->neighbors.push_back(cloneNode(n));
            }else{
                new_node->neighbors.push_back(ex_nodes[n->val]);
            }
        }
        return new_node;
    }
};
