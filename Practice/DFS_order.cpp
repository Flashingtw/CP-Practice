#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
typedef long long ll;

vector<int> adj[N];
int in[N],out[N];
int timer=0;
ll bit[N];
int n,m;

void dfs(int u,int p){
    in[u]=++timer;
    for(int v:adj[u]){
        if(v==p) continue;
        dfs(v,u);
    }
    out[u]=timer;
}
//build use in[u]
//query use out[i] - in[i-1]
