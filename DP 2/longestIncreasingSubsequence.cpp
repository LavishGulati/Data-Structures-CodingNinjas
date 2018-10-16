using namespace std;

int lis(int arr[], int n) {
    int *dp = new int[n];
    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
    }

    int max = 0;
    for(int i = 0; i < n; i++){
        if(dp[i] > max) max = dp[i];
    }
    delete[] dp;

    return max;
}
