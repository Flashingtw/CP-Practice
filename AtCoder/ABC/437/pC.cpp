#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;
    cin>>n;
    ll sum=0;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        int p,w;
        cin>>w>>p;
        sum+=p;
        v[i]=w+p;
    }
    sort(v.begin(),v.end());
    int cnt=0;
    for(auto &i:v){
        sum-=i;
        if(sum>=0) cnt++;
        else break;
    }
    cout << cnt << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}