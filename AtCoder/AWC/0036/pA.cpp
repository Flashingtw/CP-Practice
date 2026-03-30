#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> lib(n+1);
    for(int i=1;i<=n;i++){
        int m;
        cin>>m;
        lib[i].resize(m+1);
        for(int j=1;j<=m;j++){
            cin>>lib[i][j];
        }
    }
    int q,cnt=0;
    cin>>q;
    while(q--){
        int v,d;
        cin>>v>>d;
        if(lib[v][d]){
            lib[v][d]--;
        }
        else{
            cnt++;
        }
    }
    for(int i=1;i<=n;i++){
        int sz = lib[i].size();
        for(int j=1;j<sz;j++){
            cout << lib[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << cnt;
}