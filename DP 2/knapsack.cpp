int knapsack(int* weights, int* values, int n, int maxWeight){
    int **dp = new int *[2];
    dp[0] = new int[maxWeight+1];
    dp[1] = new int[maxWeight+1];

    int id = 0;
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= maxWeight; w++){
            if(i == 0 || w == 0) dp[id][w] = 0;

            if(weights[i] > w){
                dp[id][w] = dp[id^1][w];
            }
            else{
                int a = values[i]+dp[id^1][w-weights[i]];
                int b = dp[id^1][w];

                dp[id][w] = max(a, b);
            }
        }
        id = id^1;
    }

    return dp[id^1][maxWeight];
}
