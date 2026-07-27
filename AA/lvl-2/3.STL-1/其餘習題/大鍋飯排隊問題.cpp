#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
vector<int> v(1e6+5);
void solve(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,Q;
    cin>>n>>Q;
    vector<int> in(n+1);
    vector<queue<int>> group(n+1);
    queue<int> q;
    for(int i=1;i<=n;i++){
        int c;
        cin>>c;
        for(int j=0;j<c;j++){
            int x;
            cin>>x;
            v[x]=i;
        }
    }
    while(Q--){
        int t;
        cin>>t;
        if(t==1){
            int x;
            cin>>x;
            if(!in[v[x]]) {
                q.push(v[x]);
                in[v[x]] = 1;
            }
            group[v[x]].push(x);
        }
        else{
            if(q.empty()){
                cout << -1 << '\n';
                continue;
            }
            int a = q.front();
            cout << group[a].front() << '\n';
            group[a].pop();
            if(group[a].empty()) {
                q.pop();
                in[a]=0;
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}