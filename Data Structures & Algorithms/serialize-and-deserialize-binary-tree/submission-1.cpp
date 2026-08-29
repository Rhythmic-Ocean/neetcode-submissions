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

class Codec{
public:
  string serialize(TreeNode *root) {
    if (!root)
      return "#|";
    std::queue<TreeNode *> q{};
    std::string fA{};
    q.push(root);
    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();
      if (!node) {
        fA += "#|";
        continue;
      }
      fA += {std::to_string(node->val) + "|"};
      q.push(node->left);
      q.push(node->right);
    }
    return fA;
  }

  std::queue<TreeNode *> split(std::string_view str) {
    int start{};
    int end;
    queue<TreeNode *> fA{};
    while ((end = str.find('|', start)) != string_view::npos) {
      string_view s = str.substr(start, end - start);
      if (s == "#")
        fA.push(nullptr);
      else
        fA.push(new TreeNode(std::stoi(std::string(s))));
      start = end + 1;
    }
    return fA;
  }
  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    std::queue<TreeNode *> q{split(data)};
    if (q.empty() || q.front() == nullptr)
      return nullptr;
    std::queue<TreeNode *> q1{};
    TreeNode *node{q.front()};
    q.pop();
    q1.push(node);
    while (!q.empty()) {
      int size = q1.size();
      for (int i{}; i < size; ++i) {
        TreeNode *node1 = q1.front();
        q1.pop();
        if (node1 == nullptr)
          continue;
        q1.push(q.front());
        node1->left = q.front();
        q.pop();
        if (!q.empty()) {
          q1.push(q.front());
          node1->right = q.front();
          q.pop();
        }
      }
    }
    return node;
  }
};

