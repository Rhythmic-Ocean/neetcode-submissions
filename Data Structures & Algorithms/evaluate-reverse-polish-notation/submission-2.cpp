class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> operands {};
        int fT {};
        int sT {};
        for(const auto& ch: tokens){
            switch(ch[0]){
                case '+':
                    sT = operands.top();
                    operands.pop();
                    fT = operands.top();
                    operands.pop();
                    operands.push(fT + sT);
                    break; 
                case '*':
                    sT = operands.top();
                    operands.pop();
                    fT = operands.top();
                    operands.pop();
                    operands.push(fT * sT);
                    break;
                case '/':
                    sT = operands.top();
                    operands.pop();
                    fT = operands.top();
                    operands.pop();
                    operands.push(fT / sT);
                    break;
                default:
                    if(ch.size() == 1 && ch[0] == '-'){
                        sT = operands.top();
                        operands.pop();
                        fT = operands.top();
                        operands.pop();
                        operands.push(fT - sT);
                        continue;
                    }
                    operands.push(stoi(ch));
            }
        }
        return operands.top();
    }
};
