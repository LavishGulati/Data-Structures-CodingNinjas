#include <bits/stdc++.h>
using namespace std;

// int getMaxMoney(int arr[], int n){
//     if(n <= 0) return 0;
//
//     int a = arr[0]+getMaxMoney(arr+2, n-2);
//     int b = getMaxMoney(arr+1, n-1);
//     return max(a, b);
// }

int getMaxMoney(int arr[], int n){
    int *dp = new int[n+1];
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        int a;

        if(i == 1) a = arr[i-1];
        else a = arr[i-1]+dp[i-2];

        int b = dp[i-1];
        dp[i] = max(a, b);
    }

    return dp[n];
}
