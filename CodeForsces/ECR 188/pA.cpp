#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n;
    cin>>n;
    vector<char> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(v[i]=='R') cnt++;
        else break;
    }
    cout << cnt+1 << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}