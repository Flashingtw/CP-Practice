#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    while (cin >> n >> m) {
        if(m==n){
            cout << m << '\n';
        }
        else cout << m+1 << '\n';
    }
}