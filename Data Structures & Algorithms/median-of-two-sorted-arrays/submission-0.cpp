class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) std::swap(nums1, nums2);
        int n1 = nums1.size();
        int n2 = nums2.size();
        int total {n1 + n2};
        int left {n1 +(n2 - n1 + 1)/2};
        int l {};
        int r {n1};
        while(l <= r){
            int i = (l+ (r- l)/2);
            int j = left - i;
            int Aleft {(i <= 0)?INT_MIN: nums1[i - 1]};
            int Aright{(i >= n1)? INT_MAX: nums1[i]};
            int Bleft{(j<=0)? INT_MIN: nums2[j- 1]};
            int Bright{(j >= n2)? INT_MAX: nums2[j]};
            if(Aleft <= Bright && Bleft <= Aright){
                if(total % 2 != 0){
                    return std::max(Aleft, Bleft);
                }
                else{
                    return (std::max(Aleft, Bleft) + std::min(Aright, Bright))/2.0;
                }
            }
            else if(Aleft > Bright){
                r= i - 1;
            }
            else l= i + 1;
        }
        return -1;
    }
};
