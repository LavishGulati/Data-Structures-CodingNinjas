#include <bits/stdc++.h>
using namespace std;

int mcm(int* p, int n){
    int **dp = new int *[n];
    for(int i = 0; i < n; i++) dp[i] = new int[n];

    for(int i = 0; i < n; i++){
        dp[i][i] = 0;
    }

    int i = 0, j = 1;
    while(j < n){
        while(i+j < n){
            int x = i;
            int minWays = INT_MAX;

            while(x < i+j){
                // cout << i << " " << i+j << endl;
                minWays = min(minWays, dp[i][x] + dp[x+1][i+j] + p[i]*p[x+1]*p[i+j+1]);
                x++;
            }

            dp[i][i+j] = minWays;

            i++;
        }
        i = 0;
        j++;
    }

    return dp[0][n-1];
}

int main(){

    int n;
    cin >> n;
    int* p = new int[n];

    for(int i = 0; i <= n; i++){
        cin >> p[i];
    }

    cout << mcm(p, n) << endl;

}
