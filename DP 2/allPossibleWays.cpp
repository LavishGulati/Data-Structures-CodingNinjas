#include <bits/stdc++.h>
using namespace std;

int allWays(int x, int n, int a){
    if(x == 0) return 1;
    if(x < 0) return 0;

    if(a > x) return 0;

    int y = allWays(x-pow(a,n), n, a+1);
    int z = allWays(x, n, a+1);
    return y+z;
}

int allWays(int x, int n) {
    return allWays(x, n, 1);
}
