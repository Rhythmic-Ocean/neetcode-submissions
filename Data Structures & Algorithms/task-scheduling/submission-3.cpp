class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    int tick = 1;
    auto cmp = [](pair<char, int> a, pair<char, int> b) {
      return a.second < b.second;
    };
    std::vector<int> alphabet_array(26);
    for (auto task : tasks) {
      alphabet_array[task - 'A']++;
    }
    std::priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)>
        task_freq{cmp};
    for (int i{}; i < 26; ++i) {
      if (alphabet_array[i] > 0) {
        task_freq.push({'A' + i, alphabet_array[i]});
      }
    }
    std::queue<pair<char, pair<int, int>>> task_scheduler{};
    while (!task_freq.empty() || !task_scheduler.empty()) {
      if (!task_freq.empty()) {
        auto &task = task_freq.top();
        if (task.second > 1)
          task_scheduler.push(
              make_pair(task.first, make_pair(task.second - 1, tick + n + 1)));
        task_freq.pop();
        ++tick;
        if(tick >= task_scheduler.front().second.second)
        while (!task_scheduler.empty() &&
               task_scheduler.front().second.second <= tick) {
          auto &task = task_scheduler.front();
          task_freq.push({task.first, task.second.first});
          task_scheduler.pop();
        }
      } else {
        tick = max(task_scheduler.front().second.second, tick);
        while (!task_scheduler.empty() &&
               task_scheduler.front().second.second <= tick) {
          auto &task = task_scheduler.front();
          task_freq.push({task.first, task.second.first});
          task_scheduler.pop();
        }
      }
    }
    return --tick;
  }
};
