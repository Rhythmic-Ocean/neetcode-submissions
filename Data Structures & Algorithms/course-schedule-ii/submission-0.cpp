class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>> dependencies (numCourses);
       deque<int> q {};
       vector<int> indegree (numCourses);
       vector<int> finalAns {};
       for(auto& a : prerequisites){
            dependencies[a[1]].push_back(a[0]); 
            indegree[a[0]]++;
       }
       for(int i {}; i < indegree.size(); ++i){
        if(indegree[i] == 0) q.push_back(i);
       }
       while(!q.empty()){
            int vertex = q.front();
            q.pop_front();
            finalAns.push_back(vertex);
            for(auto j: dependencies[vertex]){
                indegree[j]--;
                if(indegree[j] == 0) q.push_back(j);
            }     
       }
       if(finalAns.size() == numCourses) return finalAns;
       return {};

    }
};
