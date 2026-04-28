#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;

ll ds(ll n){
    ll sum=0;
    while(n>0){
        sum+= n%10;
        n/=10;
    }
    return sum;
}

ll L,R,v1,v2;
ll cnt(ll a){
    ll l = L,ans=0,sum=0;
    for(ll r=L;r<=R;r++){
        sum+=ds(r);
        while(l<=r&&sum>a){
            sum-=ds(l++);
        }
        ans+=r-l+1;
    }
    return ans;
}

int main(){
    cin>>L>>R>>v1>>v2;
    cout << cnt(v2)-cnt(v1-1) << '\n';
}