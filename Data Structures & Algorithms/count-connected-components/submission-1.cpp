class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int nonCyclicEdges {};
        vector<int> disjoint(n, -1);
        for(auto& edge: edges){
            int root1 = find(disjoint, edge[0]);    
            int root2 = find(disjoint, edge[1]);    
            if(root1 == root2) continue;
            ++nonCyclicEdges;
            uni(disjoint, root1, root2);
        }
        return n - nonCyclicEdges;
    }
    int find(vector<int>& disjoint, int x){
        if(disjoint[x] < 0) return x;
        disjoint[x] = find(disjoint, disjoint[x]);
        return disjoint[x];
    }

    void uni(vector<int>& disjoint, int root1, int root2){
        if(disjoint[root1] == disjoint[root2]){
            --disjoint[root1];
            disjoint[root2] = root1;
        }else if(disjoint[root1] < disjoint[root2]){
            disjoint[root2] = root1;
        }else{
            disjoint[root1] = root2;
        }
    }
};
