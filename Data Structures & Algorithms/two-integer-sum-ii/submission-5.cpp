class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int ptr1 {};
        int ptr2  {n - 1};
        for(int i {}; i < n; ++i){
            int sum = numbers[ptr1] + numbers[ptr2];
            if(sum == target){
                return {ptr1 + 1, ptr2 + 1};
            }
            else if(sum > target){
                --ptr2;
            }
            else if(sum < target){
                ++ptr1;
            }
        }
        return {};
    }
 };
