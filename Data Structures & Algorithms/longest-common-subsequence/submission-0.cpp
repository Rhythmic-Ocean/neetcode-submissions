class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<string>> strs (m+1, vector<string>(n+1, "")); 
        for(int i {m-1}; i >= 0; --i){
            for(int j {n-1}; j >=0; --j){
                if(text1[i] == text2[j]){
                    strs[i][j] = text1[i]+strs[i+1][j+1];
                }else if(strs[i+1][j].size() >= strs[i][j+1].size()){
                    strs[i][j] = strs[i+1][j];
                }else{
                    strs[i][j] = strs[i][j+1];
                }
            }
        }
        return strs[0][0].size();
    }
};
