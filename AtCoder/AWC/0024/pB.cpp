#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
bool chk[N];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int cnt=0;
    for(int i=1;i<=k;i++){
        chk[i]=1;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(chk[a]||chk[b]) {
            chk[a]=1;
            chk[b]=1;
        }
    }
    for(int i=1;i<=n;i++) {
        if(chk[i]) cnt++;
    }
    cout << cnt;
}