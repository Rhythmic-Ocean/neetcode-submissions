class Solution {
public:
    int findMin(vector<int> &nums) {
       int left {};
       int right = nums.size() - 1;
       while(left < right){
            int mid = left + (right - left)/2;
            if(nums[mid] < nums[right]){//means mid and right are in same set, so min is left or mid or mid itself
                right = mid;
            }
            else{//mid is in left's set, but min can only be in right's set so we go search there
                left = mid + 1;
            }
       } 
       return nums[left];//when left, right and mid converge in one plce, that's the min
    }
};
