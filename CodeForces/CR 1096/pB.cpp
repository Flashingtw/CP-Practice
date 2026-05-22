#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll cntL=0,cntR=0;
    for(char c:s){
        if(c=='('){
            cntL++;
        }
        else cntR++;
    }
    cout <<  ((cntL == cntR) ? "YES" : "NO") << '\n';
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
}