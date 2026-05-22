#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    ll total=0;
    for(int &i:a) {
        cin>>i;
        total+=i;
    }
    vector<int> suf(n);
    vector<int> cnt(n+1);
    
    cnt[suf[n-1] = a[n-1]]++;
    total-=a[n-1];
    
    for(int i=n-2;i>=0;i--) {
        suf[i] = min(a[i],suf[i+1]);
        total -= suf[i];
        cnt[suf[i]]++;
    }
    int mx = *max_element(cnt.begin(),cnt.end());
    cout << total+mx-1 << '\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}