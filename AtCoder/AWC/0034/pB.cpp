#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n-1;i++) cin>>v[i];
    int cur=1;
    int ans=0;
    while(cur!=n){
        ans++;
        cur = v[cur];
    }
    cout << ans+1;
}