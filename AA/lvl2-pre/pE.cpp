#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ll n,ans=0;
    cin>>n;
    vector<ll> f,s;
    for(int i=1;i<=n;i++){
        ll a;
        cin>>a;
        f.push_back(a+i);
        s.push_back(a-i);
    }
    sort(f.begin(),f.end());
    sort(s.begin(),s.end());
    ll cnt=1;
    for(int i=0;i<f.size()-1;i++){
        if(f[i]==f[i+1]){
            cnt++;
        }
        else{
            ans+= cnt*(cnt-1)/2;
            cnt=1;
        }
    }
    ans+= cnt*(cnt-1)/2;
    cnt=1;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            cnt++;
        }
        else{
            ans+= cnt*(cnt-1)/2;
            cnt=1;
        }
    }
    ans+= cnt*(cnt-1)/2;
    cnt=1;
    cout << ans*2;
}