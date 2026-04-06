#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    long long r = n;
    while (r<=m) {
        cout << r << "\n";
        r*=n;
    }
}