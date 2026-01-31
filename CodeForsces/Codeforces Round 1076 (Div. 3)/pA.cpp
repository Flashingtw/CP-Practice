#include <bits/stdc++.h>
using namespace std;
bool solve(){
    int n,s,x;
    cin>>n>>s>>x;
    vector<int> v(n);
    int total=0;
    for(int i=0;i<n;i++) {
        cin>>v[i];
        total+=v[i];
    }
    if(s<total) return false;
    return ((total-s)%x)==0;
}
int main(){
    int t;
    cin>>t;
    while(t--) cout << (solve()?"yes":"no") << "\n";
}
