#include "d.h"

// {{0,1},{2,0},{3,2},{3,6},{8,7},{4,8},{5,4},{3,5},{3,9}}
// {{0,1},{0,2},{0,3}} {{0,1}}  
int main () {
    Solution res;
    vector<vector<int>> e1 =  {{0,1},{0,2},{0,3}};
    vector<vector<int>> e2 = {{0,1},{2,0},{3,2},{3,6},{8,7},{4,8},{5,4},{3,5},{3,9}};
    res.minimumDiameterAfterMerge(e1,e2);
}