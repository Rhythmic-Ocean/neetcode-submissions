class Solution {
    template<typename Cmp>
    int median_of_3(vector<vector<int>>& points, int low, int high, int k, Cmp comparator){
        if(high - low < 2) return high;
        int mid = low + (high - low)/2;
        if(comparator(points[mid], points[low])) std::swap(points[mid], points[low]);
        if(comparator(points[high], points[low])) std::swap(points[high], points[low]);
        if(comparator(points[high] ,points[mid])) std::swap(points[mid], points[high]);
        std::swap(points[mid], points[high - 1]);
        return high - 1 ;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> finalAns {};
        auto dist = [](vector<int> a, vector<int> b){
            float d1 = a[0]*a[0] + a[1]*a[1];
            float d2 = b[0]*b[0]+ b[1]*b[1];
            return d1 < d2;
        };
        quickSelect(points, 0, points.size() - 1, k, dist);
        for(int j = 0; j < k ; ++j){
            finalAns.push_back(points[j]);
        } 
        return finalAns;
    }

    template<typename Cmp>
    int quickSelect(vector<vector<int>>& points, int low, int high, int k, Cmp comp){
        if(low >= high) return low; 
        int mid = median_of_3(points, low, high, k, comp);
        auto pivot = points[mid];
        int i = low;
        for(int j = low; j < high; ++j){
            if(comp(points[j], pivot)){
                std::swap(points[i], points[j]);
                ++i;
            }
        }
        std::swap(points[i], points[mid]);
        if(k - 1 <= i){
            int m = quickSelect(points, low, i - 1, k, comp);
            if(m == k - 1){
                return m;
            }
        }else if(k - 1 > i){
            int m = quickSelect(points, i + 1, high, k, comp);
            if(m == k - 1){
                return m;
            }
        }
        return i;
    }
};
