#include <bits/stdc++.h>
using namespace std;    

bool check(int mid);

int devide1(int min_val, int max_val) {
    int left = min_val-1;
    int right = max_val;
    while(left < right) {
        int mid = left + right + 1 >> 1;
        if(check(mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int devide2(int min_val, int max_val) {
    int left = min_val;
    int right = max_val+1;
    while(left < right) {
        int mid = left + right >> 1;
        if(check(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}