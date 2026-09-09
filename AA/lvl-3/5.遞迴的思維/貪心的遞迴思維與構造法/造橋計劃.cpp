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

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> l,h;
    int cnt=0;
    rep(i,1,n+1){
        cin>>a[i];
        cnt+=a[i];
    }
    if(cnt!=2*n-2){
        cout << "NO" << '\n';
        return;
    }
    rep(i,1,n+1){
        if(a[i]==0){
            cout << "NO" << '\n';
            return;
        }
        else if(a[i]==1){
            l.push_back(i);
        }
        else {
            h.push_back(i);
        }
    }

    vector<pii> edg;
    while(!h.empty()){
        int u = l.back();
        int v = h.back();
        l.pop_back();
        if(--a[h.back()]==1){
            l.push_back(h.back());
            h.pop_back();
        }
        edg.push_back({u,v});
    }
    cout << "YES" << '\n';
    cout << edg.size()+1 << '\n';
    cout << l.back() << ' ' << l[l.size()-2] << '\n';
    for(auto [a,b]:edg){
        cout << a << ' ' << b << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}