class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left {};
        int right = nums.size() - 1;
        int mid {};
        while(right - left >= 0){
            mid = left + (right - left)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                right = mid - 1;
            else 
                left = mid + 1;
        }
        return -1;
    }
};
