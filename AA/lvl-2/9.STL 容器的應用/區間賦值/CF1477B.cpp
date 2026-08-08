#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i=a;i<b;++i)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<double,double> pdd;
typedef pair<char,int> pci;
typedef pair<int,char> pic;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const int INF = 1e9+9;
const ll LINF = 1e18+9;

void solve() {
    int n,q;
    cin>>n>>q;
    string s,f;
    cin>>s>>f;
    vector<pii> Q(q);
    rep(i,0,q) cin>>Q[i].F>>Q[i].S;
    reverse(all(Q));
    rep(i,0,q){
        auto [l,r] = Q[i];
        l--;
        int cnt0=0,cnt1=0;
        rep(idx,l,r){
            if(f[idx]=='0') cnt0++;
            else cnt1++;
        }
        if(cnt0==cnt1){
            cout << "NO" << '\n';
            return;
        }
        rep(idx,l,r){
            f[idx]=(cnt0>cnt1?'0':'1');
        }
    }
    if(s==f) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
/*
s改[l,r] q 次變成f
倒過來做
f每次更改[l,r] 如果0==1 ->無法更改 
*/
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}