class KthLargest {
  std::vector<int> m_heap{};
  int m_count{};
  int m_cap{};

  void buildHeap() {
    for (int i = m_count / 2; i >= 1; --i) {
      procelate_down(i);
    }
  }

  void procelate_down(int indx) {
    for (int i{indx}; i * 2 <= m_count;) {
      int old = i;
      if (i * 2 + 1 <= m_count) {
        i = std::max(i * 2, i * 2 + 1,
                     [*this](int a, int b) { return (m_heap[a] > m_heap[b]); });
      } else
        i = i * 2;
      if (m_heap[i] < m_heap[old]) {
        std::swap(m_heap[i], m_heap[old]);
      } else
        break;
    }
  }

  void procelate_up(int indx) {
    for (int i{indx}; i / 2 >= 1; i /= 2) {
      if (m_heap[i / 2] > m_heap[i])
        std::swap(m_heap[i / 2], m_heap[i]);
      else
        break;
    }
  }

public:
  KthLargest(int k, vector<int> &nums)
      : m_heap(k + 1), m_cap{k},
        m_count{min(static_cast<int>(nums.size()), k)} {
    if (nums.size() == 0) {
      m_heap.reserve(2);
      return;
    }
    int i{};
    for (; i < m_heap.size() - 1 && i < nums.size(); ++i) {
      m_heap[i + 1] = nums[i];
    }
    buildHeap();
    while (i < nums.size()) {
      if (nums[i] > m_heap[1]) {
        add(nums[i]);
      }
      ++i;
    }
  }

  int add(int val) {
    if (m_cap != m_count) {
      ++m_count;
      m_heap[m_count] = val;
      buildHeap();
      return m_heap[1];
    } else if (val <= m_heap[1]) {
      return m_heap[1];
    } else {

      m_heap[1] = val;
      procelate_down(1);
      return m_heap[1];
    }
  }
};

