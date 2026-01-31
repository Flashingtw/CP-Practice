#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int n,k;

bool enough(int len) {
    int used = 1;
    int last_pos = v[0];
    for (int i=0;i<n;i++) {
        if (v[i]>last_pos+len) {
            used++;
            last_pos=v[i];
        }
    }
    return used<=k;
}

int main() {
    cin>>n>>k;
    v.resize(n);
    for (int i=0;i<n;i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int l=0,r= v[n-1]-v[0],ans=0;
    while (l<=r) {
        int mid = (l+r)/2;
        if (enough(mid)) {
            ans = mid;
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    cout << ans;
}