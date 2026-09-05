class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int maxStone {};
        for(auto stone: stones){
            maxStone = max(maxStone, stone);
        }
        vector<int> bucket (maxStone + 1);
        for(auto stone: stones){
            bucket[stone]++;
        }
        int prev {-1};
        for(int i {maxStone}; i > 0;){
            if(bucket[i] == 0){
                --i;
                continue;
            }
            if(prev != -1){
                bucket[prev - i] ++;
                bucket[i]--;
                if(prev - i > i){
                    i = prev - i;
                    prev = -1;
                    continue;
                }
                prev = -1;
            }
            if(bucket[i] % 2 != 0){
                prev = i;
            }
            bucket[i] = 0;
            --i;
        }
        if(prev == -1) return 0;
        return prev;
    }
};
