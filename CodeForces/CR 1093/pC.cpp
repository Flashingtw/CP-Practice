#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
bool solve(){
    ll p,q;
    cin>>p>>q;
    ll k = 2*p+4*q+1;
    ll a=-1,b=-1;
    for(int i=1;i*i<=k;i++){
        if(k%i==0){
            a = i;
            b = k/i;
            ll n = (a-1)/2;
            ll m = (b-1)/2;
            if((n+1)*m>=q&&(m+1)*n>=q){
                cout << n << ' ' << m << '\n';
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--) {
        if(!solve()){
            cout << "-1" << '\n';
        }
    }   
}