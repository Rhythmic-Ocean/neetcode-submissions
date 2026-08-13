class Solution {
public:
  string minWindow(string s, string t) {
    std::unordered_map<char, int> map1, map2;
    int n1 = s.size();
    int n2 = t.size();
    if (n1 < n2)
      return "";
    for (auto const ch : t) {
      map2[ch]++;
    }
    int left{};
    int have{};
    int need = map2.size();
    int startIndx{};
    int minLen{std::numeric_limits<int>::max()};
    for (int i{}; i < n1; ++i) {
      map1[s[i]]++;
      if (map2.count(s[i]) && map2[s[i]] == map1[s[i]])
        have++;
      while (have == need) {
        if (minLen > (i - left + 1)) {
          minLen = i - left + 1;
          startIndx = left;
        }
        if (map2.count(s[left]) && map2[s[left]] == map1[s[left]] ) {
          have--;
          map1[s[left]]--;
          left++;
          break;
        }
        map1[s[left]]--;
        left++;
      }
    }
    if(minLen > n1) return "";
    return s.substr(startIndx, minLen);
  }
};

