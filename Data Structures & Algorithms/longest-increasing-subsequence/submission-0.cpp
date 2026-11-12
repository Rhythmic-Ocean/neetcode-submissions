class Solution {
    /*
    Subproblem: S(i) = longest increasing subsequence from i to n-1 that includes A[i]
    Relate: S(i) = 1+ max{S(j) | i < j < |A|, A[j] > A[i]}
    Base: S(|A|-1) = 1 i.e just includes A[i]
    Original: S(0) 
    */
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxLIS {};
        if(nums.empty()) return maxLIS;
        int n = nums.size();
        vector<int> maxLISIdx (nums.size()); 
        maxLISIdx[n-1] = 1;
        maxLIS = 1;
        for(int i {n-2}; i >=0; --i){
            int maxLocalLIS {};
            for(int j {i+1}; j < n; ++j){
                if(nums[j] > nums[i]){
                    maxLocalLIS = max(maxLocalLIS, maxLISIdx[j]);
                }
            }
            maxLISIdx[i] = 1+maxLocalLIS;
            maxLIS = max(maxLISIdx[i], maxLIS);
        } 
        return maxLIS;
    }
};
