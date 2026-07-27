#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n;
    cin>>n;
    if (n==1) {
        cout << "A\n";
        return;
    }
    if(n&1){
        cout << (char)('A'+n/2);
        cout << (char)('A'+n/2-1);
        for(int i=n-1;i>=0;i--){
            if(i==n/2) continue;
            if(i==n/2-1) continue;
            cout << (char)('A'+i);
        }
    }
    else{
        cout << (char)('A'+n/2-1);
        for(int i=n-1;i>=0;i--){
            if(i==n/2-1) continue;
            cout << (char)('A'+i);
        }
    }
    cout << '\n';
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}