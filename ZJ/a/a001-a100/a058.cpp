#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    int c0 = 0, c1 = 0, c2 = 0;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % 3 == 0) c0++;
        else if (x % 3 == 1) c1++;
        else c2++;
    }
    cout << c0 << " " << c1 << " " << c2 << '\n';
}