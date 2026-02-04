#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 2505;
const long long INF = 1e18;

int n,m;
vector<pii> adj[N];

vector<long long> dist;
vector<bool> in_queue;
vector<int> cnt;
vector<int> p;
bool SPFA(int start){
    queue<int> q;
    q.push(start);
    p[start]=0;
    dist[start]=0;
    in_queue[start]=1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        in_queue[u]=0;
        for(pii &ed:adj[u]){
            int v = ed.first;
            int cost = ed.second;
            if(dist[u]+cost<dist[v]){
                dist[v]=dist[u]+cost;
                p[v]=u;
                cnt[v]++;
                if(cnt[v]>=n) {
                    cout << "YES" << "\n";
                    int cur = v;
                    for (int i = 0; i < n; i++) cur = p[cur];
                    vector<int> ans;
                    int end_node = cur;
                    while(1){
                        ans.push_back(cur);
                        if(cur==end_node&&ans.size()>1) break;
                        cur = p[cur];
                    }
                    reverse(ans.begin(),ans.end());
                    for(int i:ans) cout << i << " ";
                    return true;
                }
                if(!in_queue[v]){
                    q.push(v);
                    in_queue[v]=1;
                }
            }
        }
    }
    return false;
}

int main(){
    cin>>n>>m;
    dist.assign(n+1,INF);
    in_queue.assign(n+1,0);
    cnt.assign(n+1,0);
    p.assign(n+1,-1);
    for(int i=0;i<m;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        adj[u].push_back({v,cost});
    }
    bool fnd=false;
    for(int i=1;i<=n;i++){
        if(dist[i]==INF){
            fnd = SPFA(i);
            if(fnd) break;
        }
    }
    if(!fnd) cout << "NO";
}