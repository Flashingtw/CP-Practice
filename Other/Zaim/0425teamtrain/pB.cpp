#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n;
    cin>>n;
    if(n<6) {
        cout << -1 << '\n';
        return;
    }
    int k = n/2;
    if(n&1){
        cout << 4 << '\n';
        cout << 1 << ' ' << k << ' ' << k+1 << ' ' << 2*k-1 << '\n';
    }
    else{
        cout << 3 << '\n';
        cout << 1 << ' ' << k << ' ' << k+1 << '\n';
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}