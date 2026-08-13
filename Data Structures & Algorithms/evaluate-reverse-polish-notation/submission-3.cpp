class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       std::stack<int> stack {};
       for(const auto token: tokens){
            if(token.size() == 1 && std::string{"+-/*"}.find(token[0]) != std::string::npos){
                int sT {stack.top()}; stack.pop();
                int fT {stack.top()}; stack.pop();
                switch(token[0]){
                    case '+': stack.push(fT + sT); break;
                    case '-' :stack.push(fT - sT); break;
                    case '*' :stack.push(fT * sT); break;
                    case '/' :stack.push(fT / sT); break;
                }
            }
            else{
                stack.push(stoi(token));
            }
       } 
       return stack.top();
    }
};
