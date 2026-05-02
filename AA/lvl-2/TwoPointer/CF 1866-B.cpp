#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const ll mod =  998244353;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n),an(n);
    for(int &i:a) cin>>i;
    for(int &i:an) cin>>i;
    int m;
    cin>>m;
    vector<int> b(m),bn(m);
    for(int &i:b) cin>>i;
    for(int &i:bn) cin>>i;

    int i=0,j=0;
    ll ans=1;
    while(i<n&&j<m){
        if(a[i]<b[j]){
            ans = (ans*2)%mod;
            i++;
        }
        else if (a[i]>b[j]){
            ans = 0;
            break;
        }
        else{
            if(an[i]>bn[j]){
                ans = (ans*2)%mod;
            }
            else if(an[i]<bn[j]){
                ans = 0;
                break;
            }
            i++;
            j++;
        }
    }
    while(i<n){
        ans = (ans*2)%mod;
        i++;
    }
    if(j<m) ans=0;
    cout << ans << '\n';
}
int main(){
    solve();
}