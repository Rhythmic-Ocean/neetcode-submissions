class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n  = h.size();
        std::vector<int> leftMost (n, -1);
        std::vector<int> rightMost(n, n);
        std::stack <int> myStack {};
        for(int i {}; i < n; ++i){
            while(!myStack.empty() && h[i] <= h[myStack.top()] ){
                myStack.pop();
            }
            if(!myStack.empty())
                leftMost[i] = myStack.top();
            myStack.push(i);
        }
        
        while(!myStack.empty())
            myStack.pop();

        for(int i {n - 1}; i  >= 0; --i){
            while(!myStack.empty() && h[i] <= h[myStack.top()] ){
                myStack.pop();
            }
            if(!myStack.empty())
                rightMost[i] = myStack.top();
            myStack.push(i);
        }

        int maxArea {0};
        for(int i {}; i < n; ++i){
            rightMost[i] -= 1;
            leftMost[i] += 1;
            maxArea = max(maxArea, (rightMost[i] - leftMost[i] + 1)*h[i]);
        }
        return maxArea;
    }
};
