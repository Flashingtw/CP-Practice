#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int lb(vector<int> &v,int val){
    int l=0,r=v.size()-1,ans=v.size();
    while(l<=r){
        int mid = (l+r)/2;
        if(v[mid]>=val){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return ans+1;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int cnt=0;cnt<k;cnt++){
        int q;
        cin>>q;
        cout << lb(v,q) << '\n';
    }
}