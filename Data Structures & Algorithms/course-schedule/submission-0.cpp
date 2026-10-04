class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       int counter {};
       deque<int>  q {};
       vector<vector<int>> dependencies (numCourses);
       vector<int> indegree (numCourses);
       for(int i {}; i < prerequisites.size(); ++i){
            dependencies[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
       } 
       for(int i {}; i < indegree.size(); ++i){
            if(indegree[i] == 0) q.push_back(i);
       }
       while(!q.empty()){
            auto vertex = q.front();
            q.pop_front();
            counter++;
            for(auto j: dependencies[vertex]){
                indegree[j]--;
                if(indegree[j] == 0)
                    q.push_back(j);
            }
       }
       if(counter == numCourses) return true;
       return false;
    }
};
