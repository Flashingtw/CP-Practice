#include <bits/stdc++.h>
using namespace std;
const int p = 1e9+7;
int main() {
    int t;
    cin>>t;
    vector<long long> linked(1000001,0);
    vector<long long> sep(1000001,0);
    linked[1] = 1;
    sep[1] = 1;
    for (int i=2;i<=1000000;i++) {
        sep[i] = (sep[i-1]*4+linked[i-1])%p;
        linked[i] = (linked[i-1]*2+sep[i-1])%p;
    }
    while (t--) {
        int n;
        cin>>n;
        cout << (sep[n]+linked[n])%p << "\n";
    }
}