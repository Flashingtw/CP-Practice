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
    int n,k;
    cin>>n>>k;
    vector<pii> v;
    vi cnt(n+1),col(n);
    rep(i,0,n){
        int a;
        cin>>a;
        cnt[a]++;
        v.push_back({a,i});
    }
    int sum=0;
    rep(i,1,n+1){
        sum += min(k,cnt[i]);
        cnt[i]=0;
    }
    sum = sum/k*k;
    sort(all(v));
    int clr=0;
    int count=0;
    rep(i,0,n){
        auto [a,b] = v[i];
        if(cnt[a]==k) continue;
        if(count==sum) break;
        cnt[a]++;
        col[b]=clr+1;
        clr = (clr+1)%k;
        count++;
    }
    rep(i,0,n){
        cout << col[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}