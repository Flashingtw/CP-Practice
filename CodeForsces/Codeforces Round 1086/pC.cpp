#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n;
    cin>>n;
    double s=1;
    vector<pii> v(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v[i]={a,b};
    }
    double e=0;
    for(int i=n-1;i>=0;i--){
        auto [c,p] = v[i];
        e = max(e,c+(1-p*1.0/100)*e);
    }
    cout << fixed << setprecision(7);
    cout << e << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}