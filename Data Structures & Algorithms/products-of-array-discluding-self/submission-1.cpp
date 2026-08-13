class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> prefix (nums.size(), 1);
        std::vector<int> suffix (nums.size(), 1);
        int totalProdP {1};
        int totalProdS {1};
        for(auto i {0uz}; i < nums.size(); ++i){
            prefix[i] = totalProdP;
            suffix[nums.size() - 1 - i] = totalProdS;
            totalProdP *= nums[i];
            totalProdS *= nums[nums.size() - 1 - i];
        }
        for(auto i {0uz}; i < nums.size(); ++i){
            prefix[i] *= suffix[i];
        }
        suffix.clear();
        return prefix;;
    }
};
