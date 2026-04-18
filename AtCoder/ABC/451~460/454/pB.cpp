#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int cnt[105];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int f;
        cin>>f;
        cnt[f]++;
    }
    bool chk=1;
    for(int i=1;i<=m;i++){
        if(cnt[i]>1) chk=0;
    }
    cout << (chk?"Yes":"No") << '\n';
    chk=1;
    for(int i=1;i<=m;i++){
        if(cnt[i]==0) chk=0;
    }
    cout << (chk?"Yes":"No") << '\n';
}