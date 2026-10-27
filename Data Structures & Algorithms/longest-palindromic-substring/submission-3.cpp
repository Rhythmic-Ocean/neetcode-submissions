class Solution {
    static constexpr std::array<pair<int, int>, 1> ARR{{
        {-1, 1}
    }};
public:
    string longestPalindrome(string s) {
       pair<int, int> largest {0, 0};
       int sze = 1;
       queue<pair<int, int>> q {};
       vector<vector<int>> palin(s.size(), vector<int>(s.size(), -1));
       for(int i {}; i < s.size()-1; ++i){
        palin[i][i] = 1;
        q.push({i, i});
        if(s[i] == s[i+1]){
            palin[i][i+1] = 1;
            q.push({i, i+1});
            if(sze < 2){
                sze = 2;
                largest={i, i+1};
            }
        }
       } 
       while(!q.empty()){
            int cur_i = q.front().first;
            int cur_j = q.front().second;
            q.pop();
            for(auto& arr: ARR){
                int i = cur_i+arr.first;
                int j = cur_j+arr.second;
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
       }
       return s.substr(largest.first, largest.second-largest.first+1);
    }
};
