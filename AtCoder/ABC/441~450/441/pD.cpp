#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+5;

vector<pii> adj[N];
int n,m,l,s,t;

vector<int> ans;
void dfs(int u,int sum,int step){
    if(step>=l){
        if(s<=sum&&sum<=t){
            ans.push_back({u});
        }
        return;
    }
    for(auto [v,c] :adj[u]){
        dfs(v,sum+c,step+1);
    }
}

int main(){
    cin>>n>>m>>l>>s>>t;
    for(int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
    }
    dfs(1,0,0);
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    if(ans.empty()) cout << '\n';
    for(int i:ans) cout << i << ' ';
}