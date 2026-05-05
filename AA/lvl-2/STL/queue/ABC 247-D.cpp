#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int INF = 1e9+9;
int main(){
    queue<pii> q;
    int m;
    cin>>m;
    while(m--){
        int t;
        cin>>t;
        if(t==1){
            ll x,c;
            cin>>x>>c;
            q.push({x,c});
        }
        else{
            ll c;
            cin>>c;
            ll cur=0,sum=0;
            while(cur<c){
                auto [x,n] = q.front();
                int d = c-cur;
                if(d>=n){
                    sum += n*x;
                    cur+=n;
                    q.pop();
                }
                else{
                    sum += d*x;
                    cur += d;
                    q.front().second-=d;
                }
            }
            cout << sum << '\n';
        }
    }
}   