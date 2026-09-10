
class Solution { // with quick select
public:
  int findKthLargest(vector<int> &nums, int k) {
    int indx = quickSelect(nums, 0, nums.size() - 1, k);
    if (indx == -1) {
      return -1;
    }
    return nums[indx];
  }

  int quickSelect(vector<int> &nums, int l, int h, int k) {
    if (l == h)
      return l;
    int pivot = nums[h];
    int i = l;
    for (int j = l; j < h; ++j) {
      if (nums[j] > pivot) {
        std::swap(nums[i], nums[j]);
        ++i;
      }
    }
    std::swap(nums[i], nums[h]);
    if (k - 1 > i) {
      int num = quickSelect(nums, i + 1, h, k);
      if (num == k - 1)
        return num;
    } else if (k - 1 < i) {
      int num = quickSelect(nums, l, i - 1, k);
      if (num == k - 1)
        return num;
    }
    return i;
  }
};
