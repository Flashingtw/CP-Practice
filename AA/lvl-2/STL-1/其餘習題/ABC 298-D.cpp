#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 6e5+5;
const ll mod = 998244353;
int fr=0;
ll ten[N];
void popf(){
    fr++;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int q;
    cin>>q;
    ten[0]=1;
    for(int i=1;i<=q;i++){
        ten[i] = (ten[i-1]*10)%mod;
    }

    vector<int> v = {1};
    ll ans=1;
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int x;
            cin>>x;
            v.push_back(x);
            ans=(ans*10+x)%mod;
        }
        else if (t==2){
            int sz = v.size()-fr-1;
            ans = ((ans-v[fr]*ten[sz])%mod +mod)%mod;
            popf();
        }
        else{
            cout << ans << '\n';
        }
    }
}