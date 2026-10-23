class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
       int n = nums.size();
       vector<int> arr(n);
       arr[n-1] = nums[n-1];
       arr[n-2] = max(arr[n-1], nums[n-2]);
       for(int i {n-3}; i >= 0; --i){
            arr[i] = max(arr[i+1], nums[i] + arr[i+2]);
       }
       return arr[0];
    }
};
