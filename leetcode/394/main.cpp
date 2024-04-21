#include "d.h"

int main () {
    Solution res;
    vector<vector<int>> edges = {{0,1,4},{0,2,1},{1,3,2},{1,4,3},{1,5,1},{2,3,1},{3,5,3},{4,5,2}};
    res.findAnswer(6,edges);
}