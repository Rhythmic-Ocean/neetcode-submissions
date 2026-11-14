class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<int> oldVec(n+1, 0);
        for(int i {m-1}; i >= 0; --i){
            vector<int> vec(n+1, 0);
            for(int j {n-1}; j >=0; --j){
                if(text1[i] == text2[j]){
                    vec[j] = 1 + oldVec[j+1];
                }else{
                    vec[j] = max(vec[j+1], oldVec[j]);
                }
            }
            oldVec = std::move(vec);
        }
        return oldVec[0];
    }
};
