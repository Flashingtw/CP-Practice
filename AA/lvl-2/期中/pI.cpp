#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 1e6+5;
vector<int> pos[N];
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> v(n);
    for(int &a:v) cin>>a;
    if(b<a){
        cout << 0 << '\n';
        return 0;
    }
    ll ans=0;
    int l=0,r=-1;
    for(int i=0;i<n;i++){
        int x = v[i];
        pos[x].push_back(i);
        int sz = pos[x].size();
        if(sz>=a){
            r = max(r,pos[x][sz-a]);
        }
        if(sz>b){
            l = max(l,pos[x][sz-b-1]+1);
        }
        if(r>=l) ans+= r-l+1;
    }
    cout << ans << '\n';
}