class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       std::priority_queue<int> maxHeap {};
       std::queue<pair<int, int>> q {};
       vector<int> freq (26);
       for(auto task: tasks)
            freq[task - 'A']++;
       for(auto fre: freq){
        if(fre > 0)
            maxHeap.push(fre);
       }
       int time {};
       while(!q.empty() || !maxHeap.empty()){
            time ++;
            if(maxHeap.empty()){
                time = q.front().second;
            }else{
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if(cnt > 0)
                    q.push({cnt, time + n});
            }
            if(!q.empty() && q.front().second <= time){
                maxHeap.push(q.front().first);
                q.pop();
            }
       }
       return time;
    }
};
