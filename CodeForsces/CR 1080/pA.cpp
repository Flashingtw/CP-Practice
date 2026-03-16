#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    bool chk=false;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(v[i]*v[j]==67) {
                chk=true;
                break;
            }
        }
    }
    cout << (chk?"YES":"NO") << "\n";
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
}