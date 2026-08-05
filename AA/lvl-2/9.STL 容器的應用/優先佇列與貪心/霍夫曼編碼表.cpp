#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
typedef pair<int,char> pic;
const int INF = 1e9+9;
const int N = 6e4+5;
vector<pic> adj[2*N];
string ans[N];
void dfs(int u,int d,string &s){
    if(adj[u].empty()){
        ans[u]=s;
        return;
    }
    for(auto [v,c]:adj[u]){
        s.push_back(c);
        dfs(v,d+1,s);
        s.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int &i:a) cin>>i;
    priority_queue<pli,vector<pli>,greater<pli>> pq;
    for(int i=0;i<n;i++){
        pq.push({a[i],i});
    }
    int cnt=n;
    while(pq.size()>1){
        pli x = pq.top();
        pq.pop();
        pli y = pq.top();
        pq.pop();
        adj[cnt].push_back({x.second,'0'});
        adj[cnt].push_back({y.second,'1'});
        pq.push({x.first+y.first,cnt++});
    }
    string s="";
    dfs(cnt-1,0,s);
    if(n==1) {
        cout << 0 << '\n';
        return 0;
    }
    for(int i=0;i<n;i++) cout<< ans[i] << '\n';
}