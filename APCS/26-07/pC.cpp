#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int a[1005];
ll ans=0;

void rec(int l,int r,int d){
    if(r<l) return;
    int idx=-1,mn=1e9;
    for(int i=l;i<=r;i++){
        if(a[i]<mn){
            idx = i;
            mn = a[i];
        }
    }
    ans+=mn*d;
    rec(l,idx-1,d+1);
    rec(idx+1,r,d+1);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    rec(0,n-1,1);
    cout << ans << '\n';
}