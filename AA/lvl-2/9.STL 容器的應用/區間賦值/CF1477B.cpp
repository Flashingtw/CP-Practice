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
map<int,int> mp;
string s,f;
int n,q;

void split(int i){
    auto it = mp.lower_bound(i);
    if(it->first!=i){
        int tmp = prev(it)->second;
        mp[i] = tmp;
    }
}

bool merge(int l,int r){
    auto itl = mp.find(l),itr = mp.find(r);
    int cnt1=0,cnt0=0;
    for(auto it=itl;it!=itr;it++){
        int c = next(it)->first-it->first;;
        if(it->second) cnt1+=c;
        else cnt0+=c;
    }
    if(cnt1==cnt0) return 0;
    mp.erase(itl,itr);
    mp[l] = cnt1>cnt0;
    return 1;
}
void solve() {
    mp.clear();
    cin>>n>>q;
    cin>>s>>f;
    vector<pii> Q(q);
    rep(i,0,q) cin>>Q[i].F>>Q[i].S;
    reverse(all(Q));
    mp[0] = f[0]-'0';
    rep(i,1,n){
        if(f[i]!=f[i-1]) mp[i] = f[i]-'0';
    }
    mp[n]=0;
    rep(i,0,q){
        auto [l,r] = Q[i];
        l--;
        split(l),split(r);
        if(!merge(l,r)){
            cout << "NO" << '\n';
            return;
        }
    }
    auto it = mp.begin();
    rep(i,0,n){
        if(next(it)->first==i){
            it++;
        }
        if((it->second)^(s[i]-'0')){
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
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