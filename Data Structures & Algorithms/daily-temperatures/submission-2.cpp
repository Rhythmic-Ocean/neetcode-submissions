class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       std::stack<int> myStack {};
       std::vector<int> finalAns (temperatures.size());
       for(auto i {0uz}; i < temperatures.size(); ++i){
            if(myStack.empty())
                myStack.push(i);
            else{
                    int curr_tmp {myStack.top()};
                while(temperatures[curr_tmp] < temperatures[i] ){
                    finalAns[curr_tmp] = i - curr_tmp;
                    myStack.pop();
                    if(myStack.empty())
                        break;
                    curr_tmp = myStack.top();
                }
                myStack.push(i);
            }
       } 
       return finalAns;
    }
};
