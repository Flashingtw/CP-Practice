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
struct ev{
    int a,b,c,d;
};
int n,m,q;
ll ans;
vector<ev> v;
void dfs(int cur,int las,vector<int> &arr){
    if(cur==n){
        ll cnt=0;
        for(auto [a,b,c,d]:v){
            if(arr[b]-arr[a]==c) cnt+=d;
        }
        ans = max(ans,cnt);
        return;
    }
    for(int i=las;i<=m;i++){
        arr.push_back(i);
        dfs(cur+1,i,arr);
        arr.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m>>q;
    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a--,b--;
        v.push_back({a,b,c,d});
    }
    vector<int> v;
    dfs(0,1,v);
    cout << ans << '\n';
}