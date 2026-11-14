class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<int> vec(n+1, 0);
        int diag{};
        for(int i {m-1}; i >= 0; --i){
            diag = 0; 
            for(int j {n-1}; j >=0; --j){
                int temp = vec[j];
                if(text1[i] == text2[j]){
                    vec[j] = 1 + diag;
                }else{
                    vec[j] = max(vec[j], vec[j+1]);
                }
                diag = temp;
            }
        }
        return vec[0];
    }
};
