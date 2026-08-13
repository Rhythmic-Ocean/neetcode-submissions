class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int n1 = piles.size();
    int maxi {*std::max_element(piles.begin(), piles.end())};
    int left{1};
    int right{maxi};
    int min_rate{maxi};
    int cur_time{};
    while (left <= right) {
      int mid = left + (right - left) / 2;
      for (const auto n : piles) {
        cur_time += (n - 1) / mid + 1;
      }
      if (cur_time > h)
        left = mid + 1;
      else  {
        min_rate = mid;
        right = mid - 1;
      } 
      cur_time = 0;
    }
    return min_rate;
  }
};

