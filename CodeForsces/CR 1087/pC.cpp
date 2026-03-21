#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=2*n-4;i+=2){
        cout << "? " << i << ' ' << i+1 << endl;
        int r;
        cin>>r;
        if(r==1){
            cout << "! "<< i << endl;
            return;
        }
    }
    cout << "? " << 2*n-3 << ' ' << 2*n-2 << endl;
    int r1;cin>>r1;
    if(r1) {cout << "! "<< 2*n-3 << endl; return;}
    cout << "? " << 2*n-2 << ' ' << 2*n-1 << endl;
    int r2;cin>>r2;
    if(r2) {cout << "! "<< 2*n-2 << endl; return;}
    cout << "? " << 2*n-1 << ' ' << 2*n-3 << endl;
    int r3;cin>>r3;
    if(r3) {cout << "! "<< 2*n-1 << endl; return;}

    cout << "! " << 2*n << endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();    
}