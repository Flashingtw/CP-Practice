#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> x(n);
    vector<int> y(n);
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int mx= x[n/2];
    int my= y[n/2];
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+= abs(mx-x[i]);
        ans+= abs(my-y[i]);
    }
    cout << ans;
}
