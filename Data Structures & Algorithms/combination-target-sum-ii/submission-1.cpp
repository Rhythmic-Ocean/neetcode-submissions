class Solution {
    vector<vector<int>> finalAns {};
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::ranges::sort(candidates);
        vector<int> newVec {};
        for(int i {}; i < candidates.size(); ++i){
            if(i > 0 && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] > target) break;
            newVec.push_back(candidates[i]);
            backtracking(candidates, target, candidates[i], i, newVec);
            newVec.pop_back();
        }
        return finalAns;
    }

    void backtracking(vector<int>& candidates, int target, int sum, int indx, vector<int>& curVec){
        if(sum == target){
            finalAns.push_back(curVec);
            return;
        }
        for(int i {indx+1}; i < candidates.size(); ++i){
            if(i > indx+1 && candidates[i] == candidates[i - 1]) continue;
            if(sum + candidates[i] > target) return;
            curVec.push_back(candidates[i]);
            backtracking(candidates, target, sum + candidates[i], i, curVec);
            curVec.pop_back();
        }
        return;
    }
};
