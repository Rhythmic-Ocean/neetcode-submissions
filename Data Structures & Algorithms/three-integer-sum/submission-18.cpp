class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<int>> finalAns{};
        std::sort(nums.begin(), nums.end());
        int target {};
        int ptr1 {};
        int ptr2 {n - 1};
        int i {};
        target = -nums[i];
        ptr1 = i+1;
        ptr2 = n-1;
        while(ptr1 < ptr2){
            int sum {nums[ptr1] + nums[ptr2]};
            if(sum == target){
                finalAns.push_back({nums[i], nums[ptr1], nums[ptr2]});
                while(ptr1 < ptr2 && nums[ptr1] == nums[ptr1 + 1]) ++ptr1;
                while(ptr1 < ptr2 && nums[ptr2] == nums[ptr2 - 1]) --ptr2;
                --ptr2;
                ++ptr1;
            }
            else if(sum > target){
                --ptr2;
            }
            else if(sum < target){
                ++ptr1;
            }
        }
        for(int i {1}; i < n; ++i){
            if(nums[i] == nums[i - 1]) continue;
            target = -nums[i];
            ptr1 = i+1;
            ptr2 = n-1;
            while(ptr1 < ptr2){
                int sum {nums[ptr1] + nums[ptr2]};
                if(sum == target){
                    finalAns.push_back({-target, nums[ptr1], nums[ptr2]});
                    while(ptr1 < ptr2 && nums[ptr1] == nums[ptr1 + 1]) ++ptr1;
                    while(ptr1 < ptr2 && nums[ptr2] == nums[ptr2 - 1]) --ptr2;
                    --ptr2;
                    ++ptr1;
                }
                else if(sum > target){
                    --ptr2;
                }
                else if(sum < target){
                    ++ptr1;
                }
            }
        }
        return finalAns;
    }
};
