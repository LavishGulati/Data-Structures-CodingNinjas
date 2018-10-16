#include <bits/stdc++.h>
using namespace std;

int main(){
    int total = 0;
    for(int i = 1; i < 1085; i++){
        if(__gcd(i, 1085-i) == 35) total++;
    }
    total /= 2;
    cout << total << endl;
}
