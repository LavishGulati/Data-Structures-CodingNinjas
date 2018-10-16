#include <bits/stdc++.h>
using namespace std;

int main(){
    int total = 0;
    for(int i = 10; i < 100; i++){
        int divisor = i%10 + i/10;
        if(i%divisor == 3) total++;
    }
    cout << total << endl;
}
