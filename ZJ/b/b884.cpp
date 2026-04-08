#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        long long x, y;
        cin >> x >> y;
        
        long long yee = 100 - (x + y);
        
        if (yee > 0 && yee <= 30) {
            cout << "sad!\n";
        } else if (yee > 30 && yee <= 60) {
            cout << "hmm~~\n";
        } else if (yee > 60 && yee < 100) {
            cout << "Happyyummy\n";
        } else {
            cout << "evil!!\n";
        }
    }
}