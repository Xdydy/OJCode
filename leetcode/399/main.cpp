#include "d.h"

int main() {
    Solution res;
    // vector<int> nums = {3,5,9};
    // vector<vector<int>> q = {{1,-2},{0,-3}};
    vector<int> nums = {-2,0,2,1,-2,2};
    vector<vector<int>> q = {{5,-1},{3,-1}};
    res.maximumSumSubsequence(nums,q);
}