#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> &v,int i,vector<int> &cur){
    if(cur.size()==6){
        for(int a:cur) cout << a << ' ';
        cout << '\n';
        return;
    }
    for(int j=i;j<v.size();j++){
        cur.push_back(v[j]);
        dfs(v,j+1,cur);
        cur.pop_back();
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int> v(n),cur;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    dfs(v,0,cur);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}