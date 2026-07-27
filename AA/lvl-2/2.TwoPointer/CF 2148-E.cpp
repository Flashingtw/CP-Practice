#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
bool solve(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    vector<int> cnt(n+1),need(n+1);
    for(int &i:v) {
        cin>>i;
        cnt[i]++;
    }
    for(int i=1;i<=n;i++){
        if(cnt[i]==0) continue;
        if(cnt[i]%k!=0||k>cnt[i]) return 1;
        need[i] = cnt[i]/k;
        cnt[i]=0;
    }
    ll ans=0;
    int r=0;
    for(int l=0;l<n;l++){
        while(r<n&&cnt[v[r]]<need[v[r]]){
            cnt[v[r++]]++;
        }
        ans+= r-l;
        cnt[v[l]]--;
    }
    cout << ans << '\n';
    return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--) {
        if(solve()){
            cout << 0 << '\n';
        }
    }
}