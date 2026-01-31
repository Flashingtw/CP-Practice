#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    int n;
    cin>>n;
    LL max_diff = 0;
    LL minimum = 10000000000;
    for (int i=0;i<n;i++) {
        LL num;
        cin>>num;
        max_diff = max(max_diff, num-minimum);
        minimum = min(minimum,num);
    }
    cout << max_diff;
}