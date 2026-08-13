class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ptr1 {};
        int ptr2 {ptr1 + 1};
        std::unordered_map<char, int> myMap {};
        int remaining_k {k};
        int cur_len {};
        int first_dif{};
        while(ptr1 < n){
            ptr2 = ptr1 + 1;
            remaining_k  = k;
            cur_len = 1;
            first_dif = -1;
            while(ptr2 < n && remaining_k >= 0){
                if(s[ptr2] != s[ptr1]){
                    if(remaining_k == k)
                        first_dif = ptr2;
                    --remaining_k;
                }
                ++cur_len;
                ++ptr2;
            }
            if(remaining_k != 0){
                cur_len += min(n - cur_len , remaining_k);
            }
            if(cur_len > myMap[s[ptr1]]){
                myMap[s[ptr1]] = cur_len;
            }
            if(first_dif > ptr1)
                ptr1 = first_dif;
            else
                break;
        }
        int max_len {};
        for(const auto p: myMap){
            if(p.second > max_len)
                max_len = p.second;
        }
        return max_len;
    }
};
