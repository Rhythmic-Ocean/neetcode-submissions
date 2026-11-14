class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int total {};
       for(int num: nums){
            total += num;
       } 
       if((total & 1) != 0) return false;
       total = total/2;

       vector<bool> dp (total+1, false);
       dp[0] = true;
       for(int num: nums){
            for(int i {static_cast<int>(dp.size()) - 1};i >= 0; --i){
                if(dp[i] && i+num <= total){
                    std::cout << i << std::endl;
                    dp[i+num] = true;
                }
            }
       }
       return dp[total];
    }
};
