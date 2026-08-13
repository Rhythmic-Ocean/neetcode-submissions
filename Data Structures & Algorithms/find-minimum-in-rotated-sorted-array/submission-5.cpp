class Solution {
public:
    int findMin(vector<int> &nums) {
       int l{};
       int r = nums.size() - 1; 
       if(nums[l] <=  nums[r]){//only 1 set exists
            return nums[l];
       }
       int mid = l + (r-1)/2;
       while(mid - l > 1 || r - mid > 1){
            if(nums[l] <= nums[mid]){
                l = mid;
            }
            else
                r = mid;
        mid = l + (r-l)/2; 
       }
       return std::min(nums[mid], std::min(nums[l], nums[r]));
    }
};
