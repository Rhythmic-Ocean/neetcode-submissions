class Solution {
public:
    string longestPalindrome(string s) {
       pair<int, int> largest {0, 0};
       int sze = 1;
       queue<pair<int, int>> q {};
       for(int i {}; i < s.size()-1; ++i){
        q.push({i, i});
        if(s[i] == s[i+1]){
            q.push({i, i+1});
            if(sze < 2){
                sze = 2;
                largest={i, i+1};
            }
        }
       } 
       while(!q.empty()){
            int i = q.front().first - 1;
            int j = q.front().second + 1;
            q.pop();
            if(i >= 0 && j < s.size()){
                if(s[i] == s[j]){
                    q.push({i, j});
                    if(j - i + 1 > sze){
                        sze = j-i+1;
                        largest={i, j};
                    }
                }
            }
       }
       return s.substr(largest.first, largest.second-largest.first+1);
    }
};
