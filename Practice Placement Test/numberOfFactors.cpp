#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000

vector<long long> fillPrime(int n){
    bool *isPrime = new bool[n+1];
    for(int i = 0; i < n+1; i++) isPrime[i] = true;
    isPrime[0] = false;
    isPrime[1] = false;

    vector<long long> prime;

    for(int i = 2; i < n+1; i++){
        if(isPrime[i]){
            prime.push_back(i);

            long long k = i;
            while(k*i <= n){
                isPrime[k*i] = false;
                k++;
            }
        }
    }

    delete[] isPrime;
    return prime;
}

int main(){
    vector<long long> prime = fillPrime(MAX);

    int *sieve = new int[MAX+1];
    for(int i = 0; i <= MAX; i++) sieve[i] = 0;

    for(int i = 0; i < prime.size(); i++){
        long long x = prime[i];
        long long k = 1;
        while(x*k <= MAX){
            sieve[x*k]++;
            k++;
        }
    }
    // for(int i = 0; i < prime.size(); i++) cout << prime[i] << endl;

    int t;
    cin >> t;
    while(t--){
        long long a, b, n;
        cin >> a >> b >> n;
        long long total = 0;
        for(int i = a; i <= b; i++){
            if(sieve[i] == n) total++;
        }

        cout << total << endl;
    }
}
