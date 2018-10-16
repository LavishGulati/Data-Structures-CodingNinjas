int solve(string S, string V){
    int n = S.length();
    int m = V.length();

    int i, j, prev;
    int dp[n+1][m+1], next[n+1][m+1];

    for(i = 0; i < n; i++){
        prev = -1;
        for(j = 0; j < m; j++){
            if(S[i] == V[j]) prev = j;
            next[i+1][j+1] = prev;
        }
    }

    for(i = 1; i <= n; i++) dp[i][0] = 1;
    for(i = 0; i <= m; i++) dp[0][i] = 1001;

    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(next[i][j] == -1) dp[i][j] = 1;
            else dp[i][j] = min(dp[i-1][j], 1+dp[i-1][next[i][j]]);
        }
    }

    return dp[n][m];
}
