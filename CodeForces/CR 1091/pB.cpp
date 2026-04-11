#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n+2),d(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    int p;
    cin>>p;
    int x = v[p];
    v[0]=x,v[n+1]=x;
    for(int i=0;i<=n;i++){
        if(v[i]!=v[i+1]){
            d[i]=1;
        }
        else d[i]=0;
    }
    int l=0,r=0;
    for(int i=0;i<p;i++) {
        if(d[i]==1) l++;
    }
    for(int i=p;i<=n;i++) {
        if(d[i]==1) r++;
    }
    cout << max(l,r) << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();    
}