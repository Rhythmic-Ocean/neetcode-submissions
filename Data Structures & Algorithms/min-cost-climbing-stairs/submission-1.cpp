class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       int n = cost.size();
       int two_steps = 0;
       int one_step = cost[n-1];
       int cur_step {};
       for(int i {n-2}; i >=0; --i){
        cur_step = min(two_steps, one_step) + cost[i];
        two_steps = one_step;
        one_step = cur_step;
       } 
       return min(one_step, two_steps);
    }
};
