class MinStack {
public:
    std::vector<int> mainStack {};
    std::vector<int> extraStack {};
    MinStack() {
        
    }
    
    void push(int val) {
        mainStack.push_back(val);
        if(extraStack.empty() || val <= extraStack.back())
            extraStack.push_back(val);
    }
    
    void pop() {
        if(!extraStack.empty() && extraStack.back() == mainStack.back())
            extraStack.pop_back();
        mainStack.pop_back();
    }
    
    int top() {
       return mainStack.back(); 
    }
    
    int getMin() {
       return extraStack.back(); 
    }
};
