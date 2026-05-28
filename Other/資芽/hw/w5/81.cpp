#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
struct ev{
    int c,e;
    bool operator<(ev oth){
        return e>oth.e;
    }
};
void solve(){
    int n,ans=0;
    cin>>n;
    vector<ev> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].c>>v[i].e;
    }
    sort(v.begin(),v.end());
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=v[i].c;
        ans = max(ans,sum+v[i].e);
    }
    cout << ans << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}