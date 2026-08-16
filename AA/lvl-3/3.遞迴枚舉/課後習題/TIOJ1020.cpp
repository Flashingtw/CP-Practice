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

int n;
vi ans;
ll cnt;
void dfs(int idx,vector<int> &v){
    if(idx==n){
        cnt++;
        if(ans.empty()||v>ans){
            ans=v;
        }
        return;
    }
    int sz = sz(v);
    for(int i=1;i<sz;i++){
        if((idx+1)%(v[i]+v[i-1])!=0) continue;
        v.insert(v.begin()+i,idx+1);
        dfs(idx+1,v);
        v.erase(v.begin()+i);
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    while(cin>>n){
        vector<int> v = {0,1};
        dfs(1,v);
        cout << cnt << '\n';
        if(cnt) {
            for(int i:ans) cout << i << ' ';
            cout << '\n';
        }
    }
}