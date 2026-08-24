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
       std::string rootStr {};
       std::string subStr {};
       std::stack <TreeNode*> rStack {};
       std::stack <TreeNode*> sStack {};
       rStack.push(root);
       sStack.push(subRoot);
       while(!rStack.empty()){
        TreeNode* node {rStack.top()};
        rStack.pop();
        if(!node) {
            rootStr.append(",#");
            continue;
        }
        rootStr.append(',' + to_string(node->val));
        rStack.push(node->right);
        rStack.push(node->left);
       } 
       while(!sStack.empty()){
        TreeNode* node {sStack.top()};
        sStack.pop();
        if(!node) {
            subStr.append(",#");
            continue;
        }
        subStr.append(',' + to_string(node->val));
        sStack.push(node->right);
        sStack.push(node->left);
       } 

       //Implementing KMP algorithm

        //std::pair<index, jump_bck>
        //building lps
        std::vector<int> lps(subStr.size());
        int i {};
        int j {i + 1};
        while(j < subStr.size()){
            if(subStr[i] == subStr[j]){
                i++;
                lps[j] = i;
                j+= 1;
            }
            else{
                if(i != 0)
                    i = lps[i - 1];
                else{
                    lps[j] = 0;
                    j += 1;
                }
            }
        }
        i = 0;
        j = 0;
        while(i < rootStr.size() && j < subStr.size()){
            if(rootStr[i] == subStr[j]){
                i++;
                j++;
            }
            else if(j != 0){
                j = lps[j - 1];
            }
            else{
                i++;
            }
        }
        if(j == subStr.size()) return true;
        return false;

    }
};
