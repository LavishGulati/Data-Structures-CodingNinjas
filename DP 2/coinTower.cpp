string solve(int n, int x, int y){
    int *dp = new int[n+1];
    for(int i = 0; i <= n; i++) dp[i] = -1;

    dp[1] = 1;
    if(x <= n) dp[x] = 1;
    if(y <= n) dp[y] = 1;

    for(int i = 1; i <= n; i++){
        if(dp[i] == -1){
            int a = 1, b = 1, c = 1;
            if(i > 1) a = dp[i-1];
            if(i > x) b = dp[i-x];
            if(i > y) c = dp[i-y];

            dp[i] = !a || !b || !c;
        }
    }

    if(dp[n]) return "Beerus";
    else return "Whis";
}
