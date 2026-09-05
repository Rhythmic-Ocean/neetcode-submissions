class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       priority_queue<int> q {};
       for(auto stone: stones){
        q.push(stone);
       } 
       while(!q.empty()){
        int i = q.top();
        q.pop();
        if(q.empty()) return i;
        int j = q.top();
        q.pop();
        q.push(abs(i - j));
       }
       return 0;
    }
};
