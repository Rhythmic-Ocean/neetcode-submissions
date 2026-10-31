class Solution {
public:
    int numDecodings(string s) {
        if(s.size() < 1) return 1;
        int decodelast = 1;
        int decodeSlast = 1;
        if(s[s.size() - 1] == '0')
            decodeSlast = 0;
        for(int i = s.size() - 2; i >= 0; --i){
            int cur = decodeSlast;
            if(s[i] == '0') {
                cur = 0;
            }
            else if(s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')){
                    cur += decodelast;
            }
            decodelast = decodeSlast;
            decodeSlast = cur;
        }
        return decodeSlast;
    }
};
