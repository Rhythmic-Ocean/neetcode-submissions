/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::deque<TreeNode*> q1{};
        deque<TreeNode*> q2 {};
        q1.push_back(p);
        q2.push_back(q);
        while(!q1.empty() && !q2.empty()){
            TreeNode* n1 = q1.front();
            TreeNode* n2 = q2.front();
            q1.pop_front();
            q2.pop_front();
            if(!n1 || !n2){
                if(n1 == n2) continue;
                return false;
            }
            if(n1->val != n2->val) return false;
            q1.push_back(n1->left);
            q1.push_back(n1->right);

            q2.push_back(n2->left);
            q2.push_back(n2->right);
        }
        if(!q1.empty() || !q2.empty()) return false;
        return true;
    }
};
