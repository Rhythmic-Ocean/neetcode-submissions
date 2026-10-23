class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
       int n = nums.size();
       vector<int> arr(n);
        int first = nums[n-1];
        int second = max(first, nums[n-2]);
        int cur {};
       for(int i {n-3}; i >= 0; --i){
            cur = max(second, nums[i] + first);
            first = second;
            second = cur;
       }
       return second;
    }
};
