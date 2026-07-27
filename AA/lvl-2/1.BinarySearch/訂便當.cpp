#include <bits/stdc++.h>
using namespace std;
int n,q;
int query(vector<int> &v,int val){
    int l=0,r=v.size()-1,ans=-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(v[mid]<=val){
            ans = v[mid];
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return ans;
}
int main(){
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    while(q--){
        int a;
        cin>>a;
        cout << query(v,a) << '\n'; 
    }
}