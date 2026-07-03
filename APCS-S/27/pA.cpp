#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    map<pii,pii> ans;
    map<pii, int> dist;
    set<pii> s;
    int n;
    cin>>n;
    queue<pii> q;
    vector<pii> v(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        s.insert({a,b});
        v[i]={a,b};
    }
    for(auto &[a,b]:s){
        for(int d=0;d<4;d++){
            pii np = {a+dx[d],b+dy[d]};
            if(s.find(np) == s.end()&&ans.find(np)==ans.end()){
                ans[np] = np;
                q.push(np);
                dist[np]=0;
            }
        }
    }
    while(!q.empty()){
        auto p = q.front();
        int x=p.first,y=p.second;
        q.pop();
        for(int d=0;d<4;d++){
            pii np = {p.first + dx[d], p.second + dy[d]};
            if(s.find(np) != s.end()){
                if(ans.find(np) == ans.end()){
                    ans[np] = ans[p];
                    dist[np] = dist[p]+1;
                    q.push(np);
                }
                else{
                    if(ans[p] < ans[np]&&dist[np]>=dist[p]+1){
                        ans[np] = ans[p];
                        q.push(np);
                    }
                }
            }
        }
    }
    for(auto a:v){
        cout << ans[a].first << ' ' << ans[a].second << '\n';
    }
}