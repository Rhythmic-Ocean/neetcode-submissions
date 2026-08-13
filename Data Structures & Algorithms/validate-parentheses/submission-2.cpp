class Solution {
public:
    bool isValid(string s) {
       std::stack<char> myStack {};
       for(const auto& ch: s){
        if(ch == '(' || ch == '{' || ch == '[')
            myStack.push(ch);
        else if(myStack.empty())
            return false;
        else if(ch == ')'){
            if (myStack.top() != '(')
                return false;
            myStack.pop();
        }
        else if(ch == '}'){
            if (myStack.top() != '{')
                return false;
            myStack.pop();
        }
        else if(ch == ']'){
            if (myStack.top() != '[')
                return false;
            myStack.pop();
        }
        else
            return false;

       } 
        if(!myStack.empty())
            return false;
        return true;
    }
};
