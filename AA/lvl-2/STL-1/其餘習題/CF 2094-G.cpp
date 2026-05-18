#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int q;
    cin>>q;
    int m=1;
    deque<ll> dq;
    ll rev=0,pos=0;
    bool chk=1;
    ll sum=0;
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            if(chk){
                ll a = dq.back();
                ll tot = sum-a*(m-1);
                pos+=tot;
                rev-=tot;
                dq.pop_back();
                dq.push_front(a);
            }
            else{
                ll a = dq.front();
                ll tot = sum-a*(m-1);
                pos+=tot;
                rev-=tot;
                dq.pop_front();
                dq.push_back(a);
            }
        }
        if(t==2){
            chk= !chk;
            swap(rev,pos);
        }
        if(t==3){
            ll k;
            cin>>k;
            sum+=k;
            pos+=k*m++;
            rev += sum;
            if(chk){
                dq.push_back(k);
            }
            else{
                dq.push_front(k);
            }
        }
        cout << pos << '\n';
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}