class Solution {
public:
    int countSubstrings(string s) {
        if(s.empty()) return 0;
        int counter {};
        queue<pair<int, int>> q {};
        for(int i {}; i < s.size() - 1; ++i){
            q.push({i, i});
            ++counter;
            if(s[i] == s[i+1]){
                q.push({i, i+1});
                ++counter;
            }
        }
        q.push({s.size()-1, s.size() - 1});
        ++counter;
        while(!q.empty()){
            int i = q.front().first - 1;
            int j = q.front().second + 1;
            q.pop();
            if(i >= 0 && j < s.size()){
                if(s[i] == s[j]){
                    q.push({i, j});
                    ++counter;
                }
            }
        }
        return counter;
    }
};
