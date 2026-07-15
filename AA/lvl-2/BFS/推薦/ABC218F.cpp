#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 405;
vector<int> adj[N],rev[N];
int n,m;
void bfs(){
    
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    vector<pii> v(n);
    for(auto &[a,b]:v) cin>>a>>b;
    for(auto &[a,b]:v){
        adj[a].push_back(b);
        rev[b].push_back(a);
    }
    vector<int> dist_s(n+1),dist_e(n+1);
    for(int i=0;i<n;i++){
        
    }
}