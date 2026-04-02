#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,m,t;
    cin>>n>>m>>t;
    vector<int> v(n+1,0),cnt(n+1,0);
    for(int i=0;i<m;i++){
        int c,s;
        cin>>c>>s;
        v[c]+=s;
        cnt[c]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(cnt[i]==0) continue;
        if(v[i]<t*cnt[i]) ans++;
    }
    cout << ans;
}