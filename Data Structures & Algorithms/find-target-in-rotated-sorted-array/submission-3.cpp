class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left {};
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[left] < nums[right]){
                if(target > nums[mid]) left = mid + 1;
                else right = mid - 1;
            }
            else if(nums[right] > nums[mid]){
                if(nums[mid] > target) right = mid - 1;
                else if(nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
            else{
                if(target > nums[mid]) left = mid + 1;
                else if(target < nums[mid] && target >= nums[left]) right = right - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};
