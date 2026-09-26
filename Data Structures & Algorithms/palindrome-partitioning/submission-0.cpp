
class Solution {
  std::vector<vector<string>> finalAns{};

public:
  vector<vector<string>> partition(string s) {
    if (s.size() == 0)
      return {};
    vector<string> partAns{};
    backtrack(s, partAns, 0, 0);
    return finalAns;
  }

  void backtrack(string &s, vector<string> &partAns, int indx, int start) {
    if (indx >= s.size()) {
      if (start >= s.size())
        finalAns.push_back(partAns);
      return;
    }
    if (check_palindrome(s.substr(start, indx - start + 1))) {
      partAns.push_back(s.substr(start, indx - start + 1));
      backtrack(s, partAns, indx + 1, indx + 1);
      partAns.pop_back();
    }

    backtrack(s, partAns, indx + 1, start);
    return;
  }

  bool check_palindrome(const string &str) {
    size_t ptr1 = 0;
    size_t ptr2 = str.size() - 1;
    while (ptr1 < ptr2 && str[ptr1] == str[ptr2]) {
      ++ptr1;
      --ptr2;
    }
    if (ptr1 >= ptr2)
      return true;
    return false;
  }
};
