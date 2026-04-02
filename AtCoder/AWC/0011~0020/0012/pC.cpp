#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,m;
    cin>>n>>k>>m;
    vector<long long> zero,one;
    for(int i=0;i<n;i++){
        int h,p;
        cin>>h>>p;
        if(h) one.push_back(p);
        else zero.push_back(p);
    }
    if(one.size()<m||zero.size()<k-m){
        cout << -1;
        return 0;
    }
    long long ans=0;
    sort(zero.begin(),zero.end(),greater());
    sort(one.begin(),one.end(),greater());
    for(int i=0;i<m;i++){
        ans+=one[i];
    }
    for(int i=0;i<k-m;i++){
        ans+=zero[i];
    }
    cout << ans;
}