#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,l,w;
    cin>>n>>l>>w;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    int left = lower_bound(v.begin(),v.end(),l-w)-v.begin();
    int right = upper_bound(v.begin(),v.end(),l+w)-v.begin();
    cout << right-left;
}