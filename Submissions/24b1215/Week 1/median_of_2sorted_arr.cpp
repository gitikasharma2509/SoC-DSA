#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

            vector<int> merged;

        merged.insert(merged.end(), nums1.begin(), nums1.end());

        merged.insert(merged.end(), nums2.begin(), nums2.end());

        sort(merged.begin(), merged.end());

        int x= merged.size();

        if (x% 2 == 1) {
            return merged[((x+1)/2) - 1];
        }
        else {
            return (merged[(x/2)-1] + merged[x/2]) / 2.0;
        }


        }
        
    };


int main() {

    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4, 5};

    Solution s;

    double ans = s.findMedianSortedArrays(nums1, nums2);

    cout << ans << endl;

    return 0;
}