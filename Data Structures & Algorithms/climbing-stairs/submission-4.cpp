class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        int last = 1;
        int seclast = 1;
        int cur = 0;
        for(int i {n-2}; i >= 0; --i){
            cur = (seclast + last);
            last = seclast;
            seclast = cur;
        }
        return cur;
    }

};
