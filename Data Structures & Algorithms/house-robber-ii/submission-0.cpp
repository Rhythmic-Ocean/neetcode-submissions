class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        if(nums.size() == 3) return max(nums[0], max(nums[1], nums[2]));

        //from nums 0 to n-2
        int last = nums[n-2];
        int secLst = max(nums[n-3], nums[n-2]);
        for(int i {n-4}; i >= 0; --i){
           int cur = max(last + nums[i], secLst); 
           last = secLst;
           secLst = cur;
        }
        int firstMin = secLst;
        last = nums[n - 1];
        secLst = max(nums[n-1], nums[n-2]);
        for(int i {n-3}; i > 0; --i){
           int cur = max(last + nums[i], secLst); 
           last = secLst;
           secLst = cur;
        }
        return max(secLst, firstMin);
    }
};
