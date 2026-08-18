class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast {};
        int slow {};
        while(true){
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(fast == slow) break;
        }
        int slow2 {};
        while(slow != slow2){
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow;
    }
};

