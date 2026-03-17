#include <bits/stdc++.h>
using namespace std;
vector<int> v;
long long n,k;
bool chk(long long M){
    int i=0,j=v.size()-1;
    long long ans=0;
    while(i<=j){
        if(v[i]+v[j]>=M){
            ans+= (j-i)+1;
            j--;
        }
        else i++;
    }
    return ans>=k;
}
int main(){
    cin>>n>>k;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    long long l=-2e9,r=2e9,best=-2e9;
    while(l<=r){
        long long mid = (l+r)/2;
        if(chk(mid)){
            best=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    if(best&1) cout << best << '\n' << 2;
    else cout << best/2 << '\n' << 1;
}