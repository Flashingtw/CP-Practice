#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(m);
    vector<int> cnt(n+1);
    for(int i=0;i<m;i++){
        int k;
        cin>>k;
        v[i].resize(k);
        for(int j=0;j<k;j++){
            cin>>v[i][j];
        }
        reverse(v[i].begin(),v[i].end());
    }
    vector<int> pos(n+1,-1);
    queue<int> q;
    for(int i=0;i<m;i++) q.push(i);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        int c = v[u].back();
        if(pos[c]!=-1){
            v[u].pop_back();
            v[pos[c]].pop_back();
            if(!v[u].empty()) q.push(u);
            if(!v[pos[c]].empty()) q.push(pos[c]);
            pos[c]=-1;
        }
        else{
            pos[c]=u;
        }
    }
    for(int i=0;i<m;i++){
        if(!v[i].empty()){
            cout << "No" << '\n';
            return 0;
        }
    }
    cout << "Yes" << '\n';
}