class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int p1 {};
        int p2 {p1 + 1};
        int width {};
        int total_ar {};
        std::stack< int> s{};
        while(p1 < p2 && p2 < n){
            while(p2 < n && h[p1] == 0){
                ++p1; ++p2;
            }
            if(p2 >= n){
                break;
            }
            while(!s.empty() && h[p1] > h[s.top()]){
                s.pop();
            }
            s.push(p1);
            while(p2 < n && h[p2] < h[p1]){
                s.push(p2);
                ++p2;
                ++width;
            }
            if(p2 >= n){
                break;
            }
            int ar {h[p1] * width};
            while(!s.empty() && h[p1] != h[s.top()]){
                ar -= h[s.top()];
                s.pop();
            }
            s.pop();
            total_ar += ar;
            width = 0;
            p1 = p2;
            ++p2;
        }
        while(!s.empty()){
            int m {s.top()};
            s.pop();
            if(!s.empty()){
                int b {};
                while(!s.empty() && h[m] > h[s.top()]){
                    b+= h[s.top()];
                    s.pop();
                }
                if(m - s.top() > 1){

                std::cout << h[m] << " " << m << " " << s.top()  << " " << b << std::endl;
                    total_ar += h[m] * (m - s.top() - 1) - b;
                }
               } 
            }
        return total_ar;
    }
};
