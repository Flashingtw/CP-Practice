#include <iostream>
#include <vector>
using namespace std;
long long n,m;
vector<long long> v;

bool check(long long e) {
    int used=0;
    long long last=e;
    for (int i=0;i<n;i++) {
        if (e<v[i]) {
            return false;
        }
        if (last-v[i]<0) {
            used++;
            last=e;
        }
        last-=v[i];
    }
    return used<=m;
}

int main() {
    cin>>n>>m;
    v.resize(n);
    long long total =0;
    for (int i=0;i<n;i++) {
        cin>>v[i];
        total += v[i];
    }
    long long l=1,r=total;
    long long ans=total;
    while (l<=r) {
        long long mid = (l+r)/2;
        if (check(mid)) {
            ans = mid;
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    cout << ans;
}