class MinStack {
    std::vector<long long> mainStack {};
    long long minVal {};
public:
    MinStack() {
        
    }
    
    void push(int val) {
       if(mainStack.empty()){
        mainStack.push_back(val);
        minVal = val;
       } 
       else if(val > minVal){
        mainStack.push_back(val);
       }
       else{
        mainStack.push_back(2LL*val - minVal);
        minVal = val;
       }
    }
    
    void pop() {
        long long curVal {mainStack.back()};
       if(minVal > curVal){
        minVal = 2LL*minVal - curVal;
       }
       mainStack.pop_back();
    }
    
    int top() {
        long long curVal {mainStack.back()};
       if(minVal > curVal){
        curVal = minVal; 
       }
       return curVal;
    }
    
    int getMin() {
       return minVal; 
    }
};
