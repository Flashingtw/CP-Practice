#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ll n,m,t;
    cin>>n>>m>>t;
    ll cnt=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a<t){
            cnt+= t-a;
        }
    }
    if(cnt>m) cout << -1;
    else cout << cnt;
}