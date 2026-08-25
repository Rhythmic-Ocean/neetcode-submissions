/**
 * Definition for a binary tree node.
 * struct TreeNode
{
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
    int kthSmallest(TreeNode* root, int k) {
       std::vector<int> AnsVec {};
       inorder(root, AnsVec);
       for(auto p: AnsVec){
        std::cout << p << std::endl;
       }
       return AnsVec[k - 1];
    }
    void inorder(TreeNode* root, std::vector<int>& myVec){
        if(root == nullptr) return;
        inorder(root->left, myVec);
        myVec.push_back(root->val);
        inorder(root->right, myVec);
        return;
    }
};
