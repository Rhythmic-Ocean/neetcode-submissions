class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       auto cmp = [points](vector<int> a, vector<int> b){
            float d1 = sqrt(a[0]*a[0]+ a[1]*a[1]);
            float d2 = sqrt(b[0]*b[0]+ b[1]*b[1]);
            return d1 > d2;
       };
       vector<vector<int>> finalAns {};
       std::priority_queue<vector<int>, std::vector<vector<int>>, decltype(cmp)> que (cmp, points);
       for(int i {}; i < k; ++i){
        finalAns.push_back(que.top());
        que.pop();
       }
       return finalAns;
    }
};
