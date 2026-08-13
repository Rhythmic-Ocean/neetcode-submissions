class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
       int ptr1{};
       int ptr2 {n - 1};
       int max_area {};
       int cur_area {};
       while(ptr1 < ptr2){
            cur_area = min(heights[ptr2], heights[ptr1]) * (ptr2 - ptr1);
            if(cur_area > max_area)
                max_area = cur_area;
            if(heights[ptr1] < heights[ptr2])
                ++ptr1;
            else
                --ptr2;
       } 
       return max_area;
    }
};
