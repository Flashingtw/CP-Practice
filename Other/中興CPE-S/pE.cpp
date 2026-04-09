#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    int mx=1,cur=1;
    for(int i=1;i<n;i++){
        if(v[i]==v[i-1]) cur++;
        else cur=1;
        mx = max(mx,cur);
    }
    cout << mx << '\n';
}