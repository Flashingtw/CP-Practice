#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
LL p=10009;
int n,ans=0;
vector<int> v;

void rec(int i,long long prod) {
    if (i>=n) {
        if (prod%p==1)ans++;
        return;
    }
    rec(i+1,(prod*v[i])%p);
    rec(i+1,prod);
}

int main() {
    cin>>n;
    v.resize(n+1);
    for (int i=0;i<n;i++) {
        cin>>v[i];
    }
    rec(0,1);
    cout << ans-1;
}