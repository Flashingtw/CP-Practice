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
const int N = 2e5+5;
int pre[N],in[N],in_pos[N];
int lc[N],rc[N];
bool chk;
int dfs(int pl,int pr,int l,int r){
    if(pl>pr||l>r) return 0;
    int idx = pre[pl];
    int mid = in_pos[idx];
    if(mid<l||mid>r) {
        chk=1;
        return 0;
    }
    int ls = mid-l;
    lc[idx] = dfs(pl+1,pl+ls,l,mid-1);
    rc[idx] = dfs(pl+ls+1,pr,mid+1,r);
    return idx;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    rep(i,1,n+1){
        cin>>pre[i];
    }
    rep(i,1,n+1){
        cin>>in[i];
        in_pos[in[i]]=i;
    }
    dfs(1,n,1,n);
    if(chk||pre[1]!=1){
        cout << -1 << '\n';
        return 0;
    }
    for(int i=1;i<=n;i++){
        cout << lc[i] << ' ' << rc[i] << '\n';
    }
}
/*
題目沒看完,依舊沒搞好pre ,in 的index
*/