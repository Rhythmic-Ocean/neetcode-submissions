class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        std::vector<int> indexes (n, 0);
        int i {};
        int fleet {n};
        for(auto& index: indexes){
            index = i;
            ++i;
        }
        std::sort(indexes.begin(), indexes.end(), [&position](int a, int b){
            return position[a] > position[b];
        });
        double cur_fleet_time {static_cast<double>(target - position[indexes[0]])/speed[indexes[0]]};
        for(int i {1}; i < n; ++i){
            int car {indexes[i]};
            double cur_time{static_cast<double>(target - position[car])/speed[car]};
            std::cout << cur_time << std::endl;
            if(cur_time <= cur_fleet_time){
                --fleet;
            }
            else
                cur_fleet_time = cur_time;
        }
        return fleet;
    }
};
