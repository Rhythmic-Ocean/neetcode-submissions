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
        vector<TreeNode*> s1 {};
        vector<TreeNode*> s2 {};
        s1.push_back(root);
        s2.push_back(subRoot);
        while(!s1.empty()){
            TreeNode* node {s1.back()};
            s1.pop_back();
            if(!node) continue;
            if(node->val!= subRoot->val){
                if(node->right) s1.push_back(node->right);
                if(node->left) s1.push_back(node->left);
                continue;
            }
            s1.clear();
            s1.push_back(node);
            TreeNode* backup= (node->left)?node->left:node->right;
            while(!s1.empty() && !s2.empty()){
                TreeNode * n1 = s1.back();
                TreeNode * n2 = s2.back();
                s1.pop_back();
                s2.pop_back();
                if(!n1 || !n2){
                    if(n1 != n2){
                        s2.clear();
                        s2.push_back(subRoot);
                        s1.clear();
                        s1.push_back(backup);
                        break;
                    }
                    continue;
                }
                if(n1->val != n2->val){
                    s2.clear();
                    s2.push_back(subRoot);
                    s1.clear();
                    s1.push_back(backup);
                    break;
                }
                s1.push_back(n1->right);
                s1.push_back(n1->left);

                s2.push_back(n2->right);
                s2.push_back(n2->left);
            }
        }
        if(!s2.empty()){
            std::cout << s2.back()->val << std::endl;
            return false;
        } ;
        return true;

    }
};
