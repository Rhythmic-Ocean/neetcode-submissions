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
    unordered_map<int, int> um {};
    int n {};
    int pre_indx {};
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = preorder.size();
        if(n == 0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i {}; i < n; ++i){
            um[inorder[i]] = i;
        }
        pre_indx++;
        root->left = makeTree(preorder, inorder, 0, um[root->val] - 1, pre_indx);
        root->right = makeTree(preorder, inorder, um[root->val] + 1, n - 1, pre_indx);
        return root;
    }

    TreeNode* makeTree(vector<int>&preorder, vector<int>&inorder, int l, int h, int v){
        if(l> h) return nullptr;
        if(v > preorder.size()) return nullptr;
        if(um[preorder[v]] < l || um[preorder[v]] > h) return nullptr;
        TreeNode* node = new TreeNode (preorder[v]);
        pre_indx++;
        node->left = makeTree(preorder, inorder, l, um[node->val] - 1, pre_indx);
        node->right = makeTree(preorder, inorder, um[node->val] + 1, h, pre_indx);
        return node;
    }
};
