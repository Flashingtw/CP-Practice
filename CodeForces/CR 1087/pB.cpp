#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n),ans(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        int gre=0,low=0;
        for(int j=i+1;j<n;j++){
            if(a[j]>a[i]) gre++;
            if(a[j]<a[i]) low++;
        }
        ans[i] = max(gre,low);
    }
    for(int i:ans) cout << i << ' ';
    cout << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();    
}