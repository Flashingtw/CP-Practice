#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int lef[105],rig[105];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        lef[a]++;
        rig[b]++;
    }
    for(int i=1;i<=m;i++){
        cout << rig[i]-lef[i] << '\n';
    }
}