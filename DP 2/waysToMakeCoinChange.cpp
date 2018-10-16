#include <bits/stdc++.h>
using namespace std;

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
    int **dp = new int *[numDenominations];
    for(int i = 0; i < numDenominations; i++){
        dp[i] = new int[value+1];
        dp[i][0] = 1;
    }

    for(int i = 1; i <= value; i++){
        for(int j = 0; j < numDenominations; j++){
            dp[j][i] = 0;
            for(int k = 0; k <= j; k++){
                if(i-denominations[k] >= 0){
                    dp[j][i] += dp[k][i-denominations[k]];
                }
            }
        }
    }

    return dp[numDenominations-1][value];
}
