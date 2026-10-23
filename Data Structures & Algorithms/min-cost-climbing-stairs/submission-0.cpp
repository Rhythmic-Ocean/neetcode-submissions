class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       int n = cost.size();
       vector<int> arr (n+1);
       arr[n] = 0;
       arr[n-1] = cost[n-1];
       for(int i {n-2}; i >=0; --i){
        arr[i] = min(arr[i+1], arr[i+2]) + cost[i];
       } 
       return min(arr[0], arr[1]);
    }
};
