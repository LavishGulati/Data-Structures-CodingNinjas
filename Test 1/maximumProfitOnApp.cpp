#include <bits/stdc++.h>
using namespace std;

int maximumProfit(int budget[], int n) {
    sort(budget, budget+n);

    int profit = 0;
    for(int i = 0; i < n; i++){
        int currProfit = budget[i]*(n-i);
        if(currProfit > profit) profit = currProfit;
    }

    return profit;
}
