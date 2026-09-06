class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       auto cmp = [points](int a, int b){
            float d1 = sqrt(points[a][0]*points[a][0]+ points[a][1]*points[a][1]);
            float d2 = sqrt(points[b][0]*points[b][0]+ points[b][1]*points[b][1]);
            return d1 > d2;
       };
       vector<vector<int>> finalAns {};
       std::priority_queue<int, std::vector<int>, decltype(cmp)> que (cmp);
       for(int i {}; i < points.size(); ++i){
        que.push(i);
       }
       for(int i {}; i < k; ++i){
        finalAns.push_back(points[que.top()]);
        que.pop();
       }
       return finalAns;
    }
};
