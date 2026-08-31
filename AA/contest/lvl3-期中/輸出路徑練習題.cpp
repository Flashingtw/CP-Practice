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
const int N = 2e4+5;

map<string,int> mp;
string ist[N];
vi adj[N];
int vis[N];
int st,ed;

bool dfs(int u,vector<int> &a){
    a.push_back(u);
    if(u==ed){
        return 1;
    }
    for(int v:adj[u]){
        if(vis[v]) continue;
        vis[v]=1;
        if(dfs(v,a)) return 1;
    }
    a.pop_back();
    return 0;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int cnt=1;
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        string u,v;
        cin>>u>>v;
        if(mp.find(u)==mp.end()) {
            ist[cnt]=u;
            mp[u]=cnt++;
        }
        if(mp.find(v)==mp.end()) {
            ist[cnt]=v;
            mp[v]=cnt++;
        }
        adj[mp[u]].push_back(mp[v]);
    }
    int q;
    cin>>q;
    while(q--){
        for(int i=1;i<cnt;i++){
            vis[i]=0;
        }
        string a,b;
        cin>>a>>b;
        st = mp[a];
        ed = mp[b];
        vis[st]=1;

        vi ans;
        if(st!=0&&ed!=0&&dfs(st,ans)){
            for(int i:ans){
                cout << ist[i] << ' ';
            }
            cout << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }
}
/*
詢問沒保證一定是目前有出現過的點
*/