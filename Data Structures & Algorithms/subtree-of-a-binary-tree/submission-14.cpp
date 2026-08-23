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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot){
            if(root == subRoot) return true;
            if(!subRoot) return true;
            return false;
        }
        if(isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot)){
            return true;
        }
        if(root->val== subRoot->val){
            return sameTree(root, subRoot);
        }
        return false;
    }

    bool sameTree(TreeNode* root, TreeNode* subRoot){
        stack<TreeNode*> s1 {};
        stack<TreeNode*> s2 {};
        s1.push(root);
        s2.push(subRoot);
        while(!s1.empty() && !s2.empty()){
            TreeNode* n1 = s1.top();
            TreeNode* n2 = s2.top();
            s1.pop();
            s2.pop();
            if(!n1 || !n2) {
                if(n1 != n2) return false;
                continue;
            }
            if(n1->val!= n2->val) return false;
            s1.push(n1->left);
            s1.push(n1->right);
            
            s2.push(n2->left);
            s2.push(n2->right);
        }
        return true;
    }
};
