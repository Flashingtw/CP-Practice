#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int ans = 0;
    if (n >= 40) {
        ans = 100;
    } 
    else if (n > 20) {
        ans = 80 + (n - 20) * 1;
    } 
    else if (n > 10) {
        ans = 60 + (n - 10) * 2;
    } 
    else {
        ans = n * 6;
    }
    cout << ans << '\n';
}