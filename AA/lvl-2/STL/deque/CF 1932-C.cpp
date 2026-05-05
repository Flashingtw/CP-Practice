#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    ll n,m;
    cin>>n>>m;
    deque<ll> dq;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        dq.push_back(x);
    }
    string s;
    cin>>s;
    vector<int> ans;
    for(char c:s){
        if(c=='L'){
            ans.push_back(dq.front());
            dq.pop_front();
        }
        else{
            ans.push_back(dq.back());
            dq.pop_back();
        }
    }
    ll total=1;
    reverse(ans.begin(),ans.end());
    for(int &a:ans){
        total = (total*a)%m;
        a = total;
    }
    reverse(ans.begin(),ans.end());
    for(int a:ans) cout << a << ' ';
}
int main(){
    int t;
    cin>>t;
    while(t--) {
        solve();
        cout << '\n';
    }
}