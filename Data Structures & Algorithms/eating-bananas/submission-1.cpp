class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int n1 = piles.size();
    int max{};
    int min{std::numeric_limits<int>::max()};
    for (const auto n : piles) {
      if (n > max)
        max = n;
      if (n < min)
        min = n;
    }
    int left{1};
    int right{max};
    int min_rate{max};
    int cur_time{};
    while (left <= right) {
      int mid = left + (right - left) / 2;
      for (const auto n : piles) {
        cur_time += (n - 1) / mid + 1;
      }
      if (cur_time > h)
        left = mid + 1;
      else if (mid < min_rate) {
        min_rate = mid;
        right = mid - 1;
      } else
        return min_rate;
      cur_time = 0;
    }
    return min_rate;
  }
};

