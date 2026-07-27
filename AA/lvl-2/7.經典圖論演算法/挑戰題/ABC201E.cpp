/*
Problem Statement

We have a weighted tree with N vertices. The i-th edge connects Vertex ui​ and Vertex vi​ bidirectionally and has a weight wi​.

For a pair of vertices (x,y), let us define dist(x,y) as follows:

    the XOR of the weights of the edges in the shortest path from x to y.

Find dist(i,j) for every pair (i,j) such that 1≤i<j≤N, and print the sum of those values modulo (109+7).
What is  XOR ?

The bitwise XOR of integers A and B, A XOR B, is defined as follows:

    When A XOR B is written in base two, the digit in the 2k's place (k≥0) is 1 if exactly one of A and B is 1, and 0 otherwise.

For example, we have 3 XOR 5=6 (in base two: 011 XOR 101=110).

Constraints

    2≤N≤2×105
    1≤ui​<vi​≤N
    0≤wi​<260
    The given graph is a tree.
    All values in input are integers.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int mod = 1e9+7;
const int N = 2e5+5;
struct edg{
    int v;
    ll w;
};
vector<edg> adj[N];
ll a[N];
int vis[N];
int n;
ll ans=0;
void cnt(int idx){
    ll on=0,ze=0;
    for(int i=1;i<=n;i++){
        if((a[i]>>idx)&1) on++;
        else ze++;
    }
    ll C = (on*ze)%mod;
    ans = (ans+(C*((1LL<<idx)%mod))%mod)%mod;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    queue<int> q;
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto [v,w]:adj[u]){
            if(vis[v]) continue;
            q.push(v);
            a[v] = a[u]^w;
            vis[v]=1;
        }
    }
    for(int i=0;i<61;i++) cnt(i);
    cout << ans << '\n';
}