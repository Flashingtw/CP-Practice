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

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,r;
    cin>>n>>r;
    vector<pll> v(n);
    rep(i,0,n) cin>>v[i].F>>v[i].S;
    priority_queue<ll> pq;
    ll cur=0;
    rep(i,0,r){
        cur+=v[i].F;
        pq.push(v[i].S-v[i].F);
    }
    cout << cur << '\n';
    rep(i,r,n){
        cur+=v[i].F;
        pq.push(v[i].S-v[i].F);

        cur+=pq.top();
        pq.pop();
        cout << cur << '\n';
    }
}