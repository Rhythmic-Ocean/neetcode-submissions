class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       vector<int> disjoint(edges.size(), -1); 
       for(auto& edge: edges){
        int root1 = find(disjoint, edge[0] - 1);
        int root2 = find(disjoint, edge[1] - 1);
        if(root1 == root2) return {edge[0], edge[1]};
        uni(disjoint, root1, root2);
       }
       return {};
    }
    int find(vector<int>& disjoint, int x){
        if(disjoint[x] < 0) return x;
        return disjoint[x] = find(disjoint, disjoint[x]);
    }

    void uni(vector<int>& disjoint, int root1, int root2){
        if(disjoint[root1] == disjoint[root2]){
            --disjoint[root1];
            disjoint[root2] = root1;
        }
        else if(disjoint[root1] < disjoint[root2]){
            disjoint[root2] = root1;
        }
        else {
            disjoint[root1] = root2;
        }
        return;
    }
};
