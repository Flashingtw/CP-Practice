#include <iostream>
using namespace std;
int n;
long long p,ans,a[26];

void rec(int i,long long k) {
    if (i>=n) {
        if (k<p) ans = max(ans,k);
        return;
    }
    rec(i+1,k+a[i]);
    rec(i+1,k);
}

int main() {
    cin>>n>>p;
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    rec(0,0);
    cout << ans;
}