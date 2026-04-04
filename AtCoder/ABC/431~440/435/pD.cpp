#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
vector<int> adj[N];
bool chk[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[v].push_back(u);
    }
    int q;
    cin>>q;
    while(q--){
        int type,v;
        cin>>type>>v;
        if(type==1){
            queue<int> q;
            q.push(v);
            if(chk[v]) continue;
            chk[v]=1;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int i:adj[u]){
                    if(chk[i]) continue;
                    chk[i]=1;
                    q.push(i);
                }
            }
        }
        else{
            cout << (chk[v]?"Yes":"No") << '\n';
        }
    }
}