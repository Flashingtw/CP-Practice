#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int n;
    cin>>n;
    ll cnt=0,ans=0;
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        if(a>b) {
            cnt++;
            ans+= a-b;
        }
    }
    cout << cnt << ' ' << ans;
}