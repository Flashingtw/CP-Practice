#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int cnt[(1<<20)+1];
int main(){
    int n;
    cin>>n;
    vector<int> a(n),b(n),c(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) cin>>c[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cnt[a[i]^b[j]]++;
        }
    }

    ll ans=0;
    for(int i=0;i<n;i++){
        ans += cnt[c[i]];
    }
    cout << ans;
}