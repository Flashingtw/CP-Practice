#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;

ll sqt(ll x){
    ll l = 1,r=1e9,ans=0;
    while(l<=r){
        ll mid = (l+r)/2;
        if(mid*mid<=x){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return ans;
}

int main(){
    ll x;
    cin>>x;
    cout << sqt(x) << '\n';
}