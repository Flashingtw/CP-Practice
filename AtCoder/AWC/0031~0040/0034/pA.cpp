#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 1e5+5;
int cnt[N],lmt[N];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>lmt[i];
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        if(cnt[x]<lmt[x]){
            ans++;
            cnt[x]++;
        }
    }
    cout << ans;
}