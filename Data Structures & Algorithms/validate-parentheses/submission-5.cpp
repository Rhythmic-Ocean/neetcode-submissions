class Solution {
public:
    bool isValid(string s) {
       std::vector<char> myVec{};
       myVec.reserve(s.size());
       for(const auto& ch: s){
        if(ch == '(')
            myVec.push_back(ch + 1);
        else if(ch == '{' || ch == '[')
            myVec.push_back(ch + 2);
        else if(myVec.empty() || myVec.back() != ch)
            return false;
        else
            myVec.pop_back();
       } 
        if(!myVec.empty())
            return false;
        return true;
    }
};
