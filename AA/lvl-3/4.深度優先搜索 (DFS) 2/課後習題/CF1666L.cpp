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
int vis[N],p[N];
vi adj[N];
int t;
bool dfs(int u,int c,vi &cur){
    for(int v:adj[u]){
        if(!vis[v]){
            p[v]=u;
            vis[v]=c;
            cur.push_back(v);
            if(dfs(v,c,cur)) return 1;
            cur.pop_back();
        }
        else if (vis[v]!=c){
            cout << "Possible" << '\n';
            cur.push_back(v);
            cout << cur.size() << '\n';
            for(int i:cur){
                cout << i << ' ';
            }
            cout << '\n';
            t = v;
            return 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,s;
    cin>>n>>m>>s;
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        if(v==s) continue;
        adj[u].push_back(v);
    }
    int cnt=0;
    for(int i:adj[s]){
        vi v = {s,i};
        if(!vis[i]){
            vis[i]=++cnt;
            p[i]=s;
            if(dfs(i,cnt,v)) break;
        }
        else{
            cout << "Possible" << '\n';
            cout << 2 << '\n';
            cout << s << ' ' << i << '\n';
            t = i;
            break;
        }
    }
    if(t!=0){
        vi a;
        int cur = t;
        while(cur!=s){
            a.push_back(cur);
            cur = p[cur];
        }
        a.push_back(cur);
        reverse(all(a));
        cout << a.size() << '\n';
        for(int i:a){
            cout << i << ' ';
        }
        cout << '\n';
    }
    else{
        cout << "Impossible" << '\n';
    }
}
/*
思考的時候的bug:
題目沒看清楚 以為是s,t固定 結果t隨機選

寫的時候的bug:
1 p[i]太早改
2 能讓dfs走回s
3 特判case沒輸出好
*/