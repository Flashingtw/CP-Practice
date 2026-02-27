#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    int mn=1e9,idx=-1;
    for(int i=x+1;i<=y;i++){
        if(v[i]<mn){
            idx=i,mn=v[i];
        }
    }
    vector<int> B;
    for(int i=idx;i<=y;i++) B.push_back(v[i]);
    for(int i=x+1;i<=idx-1;i++) B.push_back(v[i]);
    vector<int> S;
    for(int i=1;i<=n;i++){
        if(x<i&&i<=y) continue;
        S.push_back(v[i]);
    }
    int index=-1;
    for(int i = 0;i<S.size();i++){
        if(S[i]>mn){
            index=i;
            break;
        }
    }
    if(index==-1) index=S.size();

    for(int i=0;i<index;i++) cout << S[i] << ' ';
    for(int i:B) cout << i << ' ';
    for(int i=index;i<S.size();i++) cout << S[i] << ' ';
    cout << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}