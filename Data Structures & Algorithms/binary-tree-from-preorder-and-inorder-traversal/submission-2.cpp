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
    std::unordered_map<int, int> um {};
    int pre_indx {};
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       size_t n {inorder.size()};
       for(int i {}; i < n; ++i){
        um[inorder[i]] = i;
       }
       return makeTree(preorder, inorder, 0, n-1);
    }

    TreeNode* makeTree(vector<int>& preorder, vector<int>&inorder, int l, int h){
        if(l > h) return nullptr;
        TreeNode* node {new TreeNode(preorder[pre_indx])};
        pre_indx++;
        int mid = um[node->val];
        node->left = makeTree(preorder, inorder, l, mid - 1);
        node->right = makeTree(preorder, inorder, mid  + 1, h);
        return node;
    }
};
