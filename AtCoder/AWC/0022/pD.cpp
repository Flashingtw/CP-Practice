#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
int v[N],cnt[N];
int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> a(k);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n+1;i++){
        int b = v[i-1]^v[i];
        if(b) a[i%k].push_back(i);
    }
    ll ans=0;
    for(int r=0;r<k;r++){
        if(a[r].size()&1){
            cout << -1;
            return 0;
        }
        for(int j=0;j<a[r].size();j+=2){
            ans+= (a[r][j+1]-a[r][j])/k;
        }
    }
    cout << ans;
}