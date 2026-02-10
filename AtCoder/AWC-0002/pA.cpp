#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    bool fnd=false;
    for(int i=0;i<n;i++){
        if(v[i]==k){
            fnd=true;
            cout << i+1;
            break;
        }
    }
    if(!fnd) cout << -1;
}