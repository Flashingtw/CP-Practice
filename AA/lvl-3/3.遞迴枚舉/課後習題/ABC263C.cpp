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

int n,m;
void dfs(int cur,vector<int> &a){
    if(cur==n){
        for(int i:a) cout << i << ' ';
        cout << '\n';
        return;
    }
    int sz = sz(a);
    int las = (a.empty()?0:a.back());
    for(int i=las+1;i<=m;i++){
        a.push_back(i);
        dfs(cur+1,a);
        a.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    vector<int> a;
    dfs(0,a);
}