class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n2 < n1) return false;
        std::vector<int> myVec1 (26, 0);
        std::vector<int> myVec2 (26, 0);
        for(auto i {0uz}; i < n1; ++i){
            myVec1[s1[i] - 'a']++;
            myVec2[s2[i] - 'a']++;
        }
        if(myVec1 == myVec2) return true;
        for(auto i {n1}; i < n2; ++i){
            if(myVec1 == myVec2) return true;
            myVec2[s2[i - n1] - 'a']--;
            myVec2[s2[i]- 'a']++;
        }
        return myVec1 == myVec2;
    }
};
