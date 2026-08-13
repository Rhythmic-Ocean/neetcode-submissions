class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     auto comp = [&nums] (int a, int b){
      return nums[a] < nums[b];
     };
    std::priority_queue<int, std::vector<int>, decltype(comp)> q(comp);
    std::vector<int> fA{};
    for(int i{} ;i < k; ++i){
      q.push(i);
    }
    fA.push_back(nums[q.top()]);
    int left {};
    for(int i{k}; i < nums.size(); ++i){
        left++;
        if(nums[i] >= nums[ q.top()]){
          q.push(i);
          fA.push_back(nums[q.top()]);
          continue;
        }
        q.push(i);
        while(q.top() < left || q.top() > i){
          q.pop();
        }
        fA.push_back(nums[q.top()]);
    }
    return fA;
    }
};
