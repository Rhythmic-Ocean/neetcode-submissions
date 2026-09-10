class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       std::priority_queue q {std::less<int>(), nums};
       for(int i {}; i < k - 1; ++i){
        q.pop();
       } 
       return q.top();
    }
};
