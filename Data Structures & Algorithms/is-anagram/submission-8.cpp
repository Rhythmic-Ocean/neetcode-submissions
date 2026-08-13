class Solution {
public:
    bool isAnagram(string s, string t) {
        std::vector<int> a(26);

        if(s.size() != t.size())
            return false;
        for(const auto & c: s){
            a[c - 'a'] += 1;
        }
     
        for(const auto & c: t){
            a[c - 'a'] -= 1;
        }
        for(const auto & c : a){
            if(c != 0)
                return false;
        }
        return true;
    }
};
