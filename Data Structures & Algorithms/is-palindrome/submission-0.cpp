class Solution {
public:
    bool isPalindrome(string s) { //48-57 | 65-90 | 97-122
       int start {0};
       int end  = s.size() - 1; 
       char zero = '0';
       char nine = '9';
       char a = 'a';
       char z = 'z';
       char A = 'A';
       char Z = 'Z';
       while(start < end){
            if(!((s[start]>= zero && s[start] <= nine) || (s[start] >=a && s[start] <= z) || (s[start] >=A  && s[start] <= Z))){
                ++start;
                continue;
            }
            if(!((s[end]>= zero && s[end] <= nine) || (s[end] >=a && s[end] <= z) || (s[end] >=A  && s[end] <= Z))){
                --end;
                continue;
            }
            s[start] = (s[start] >=a && s[start] <= z)? s[start] - 'a' + 'A': s[start];
            s[end] = (s[end] >=a && s[end] <= z)? s[end] - 'a' + 'A': s[end];
            if(s[start] != s[end]){
                std::cout << s[start] << s[end] << std::endl;
                return false;
            }
            ++start;
            --end;
       }
       return true;
    }
};
