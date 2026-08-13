class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       std::unordered_set<int> mySet {};
       int n = s.size();
       int ptr {};
       int ptr1 {ptr};
       int cur_size {};
       int max_size {};
       while( ptr1 < n){
            auto output {mySet.insert(s[ptr1])};
            if(output.second){
                ++cur_size;
                ++ptr1;
            }
            else{
                while(s[ptr] != s[ptr1]){
                    --cur_size;
                    mySet.erase(s[ptr]);
                    ++ptr;
                }
                    --cur_size;
                mySet.erase(s[ptr]);
                ++ptr;
            }
            if(cur_size > max_size)
                max_size = cur_size;
       } 
       return max_size;
    }
};
