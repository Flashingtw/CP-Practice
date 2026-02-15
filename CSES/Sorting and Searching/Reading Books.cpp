#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m=-1;
    long long sum=0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
        if(v[i]>m) m=v[i];
        sum+=v[i];
    }
    if(m*2>sum) cout << m*2;
    else cout << sum;
}