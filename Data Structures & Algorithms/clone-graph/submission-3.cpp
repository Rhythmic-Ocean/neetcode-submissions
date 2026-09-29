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

//BFS solution
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
       deque<Node*> q_old {}; 
       deque<Node*> q_new{}; 
       unordered_map<int, Node*> ex_nodes{};
       Node* new_node = new Node(node->val);
       q_old.push_back(node);
       q_new.push_back(new_node);
        ex_nodes[new_node->val] = new_node;
       while(!q_new.empty()){
        Node* cur_node = q_new.front();
        q_new.pop_front();
        Node* old_node = q_old.front();
        q_old.pop_front();
        for(Node* n: old_node->neighbors){
            if(!ex_nodes.contains(n->val)){
                ex_nodes[n->val] = new Node(n->val);
                q_new.push_back(ex_nodes[n->val]);
                q_old.push_back(n);
            }
                cur_node->neighbors.push_back(ex_nodes[n->val]);
        }
       }
       return new_node;
    }
};
