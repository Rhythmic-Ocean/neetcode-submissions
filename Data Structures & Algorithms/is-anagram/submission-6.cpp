class Solution {
public:
    bool isAnagram(string s, string t) {
        int loc {-1};
        std::hash<char> ch;
        if(s.size() != t.size())
            return false;
        for(auto & c : s){
            if((loc = t.find(c)) == std::string::npos)
                return false;
            t[loc] = 0;
        }
     
        return true;
    }
};
