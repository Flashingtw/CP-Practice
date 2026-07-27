#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 1e5+5;

vector<int> fac[N];

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int &a:v) cin>>a;
    sort(v.begin(),v.end());
    vector<int> cnt((int)1e5+5);
    int l = 0;
    int cur = 0;
    int ans = 2e9;
    for(int r=0;r<n;r++){
        for(int a:fac[v[r]]){
            if(a>m) continue;
            if(cnt[a]++==0) cur++;
        }
        while(cur==m){
            ans = min(ans,v[r]-v[l]);
            for(int a:fac[v[l]]){
                if(a>m) continue;
                if(--cnt[a]==0) cur--;
            }
            l++;
        }
    }
    cout << (ans==2e9?-1:ans) << '\n';
}
int main(){
    for(int i=1;i<=1e5;i++){
        for(int k=i;k<=1e5;k+=i) fac[k].push_back(i);
    }
    int t;
    cin>>t;
    while(t--) solve();
}