#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),d(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>d[i];
    sort(a.begin(),a.end(),greater());
    sort(d.begin(),d.end(),greater());
    int p1=0,p2=0;
    ll ans=0; 
    while(p2<m){
        if(a[p1]>=d[p2]){
            ans+=a[p1]-d[p2];
            p1++;
        }
        else{
            ans=-1;
            break;
        }
        p2++;
    }
    cout << ans;
}