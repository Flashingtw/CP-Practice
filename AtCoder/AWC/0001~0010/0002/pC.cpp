#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    long long  n,m;
    cin>>n>>m;
    ll max_day=0;
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        if(a>=m) continue;
        ll d;
        if((m-a)%b==0) d = (m-a)/b;
        else d = (m-a)/b+1;
        
        max_day = max(max_day,d);
    }
    cout << max_day;
}