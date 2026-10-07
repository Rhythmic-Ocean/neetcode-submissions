class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    std::string cur_word{};
    int counter;
    wordList.push_back(beginWord);
    unordered_map<string, vector<string_view>> mapping{};
    unordered_map<string_view, int> visited{};
    deque<string_view> q{};
    for (int i{}; i < beginWord.size(); ++i) {
      for (auto &word : wordList) {
        cur_word = word;
        cur_word[i] = '_';
        mapping[cur_word].push_back(word);
      }
    }
    q.push_back(beginWord);
    visited[beginWord] = 1;
    while (!q.empty()) {
      string_view str = q.front();
      q.pop_front();
      ++counter;
      if (str == endWord)
        return visited[str];
      for (int i{}; i < str.size(); ++i) {
        std::string cur_word = std::string(str);
        cur_word[i] = '_';
        if (mapping.contains(cur_word) && mapping[cur_word].size() > 1) {
          for (auto w : mapping[cur_word]) {
            if (visited.contains(w))
              continue;
            q.push_back(w);
            visited[w] = visited[str] + 1;
          }
        }
      }
    }
    return 0;
  }
};
