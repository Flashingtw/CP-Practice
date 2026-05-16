#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n,m;
    cin>>n>>m;
    if(n==1&&m==1){
        cout << 1 << '\n';
    }
    else if (n==1||m==1){
        cout << 2 << '\n';
    }
    else if (n==m){
        cout << 8 << '\n';
    }
    else cout << 4 << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}