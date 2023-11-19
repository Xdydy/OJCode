#include "d.h"

int main () {
    Solution res;
    vector<int> height = {5,3,8,2,6,1,4,6};
    vector<vector<int>> queries = {{0,7},{3,5},{5,2},{3,0},{1,6}};
    res.leftmostBuildingQueries(height,queries);
}