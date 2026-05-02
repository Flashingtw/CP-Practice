#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    ll n,m;
    cin>>n>>m;
    deque<int> dq;
    ll total=1;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        dq.push_back(x);
        total*=x;
    }
    string s;
    cin>>s;
    for(char c:s){
        cout << total%m << ' ';
        if(c=='L'){
            total/=dq.front();
            dq.pop_front();
        }
        else{
            total/=dq.back();
            dq.pop_back();
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) {
        solve();
        cout << '\n';
    }
}