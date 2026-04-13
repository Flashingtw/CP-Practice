#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int p1,p2,p3;
int q(int mid, vector<int> ex){
    cout << "? " << mid+ex.size() << ' ';
    for(int i=1;i<=mid;i++){
        cout << i << ' ';
    } 
    for(int x:ex) cout << x << ' ';
    cout << endl;
    int x;
    cin>>x;
    return x;
}
void solve(){
    int n;
    cin>>n;
    int l = 1 , r = 2*n+1;
    while(l<=r){
        int mid = (l+r)/2;
        if(mid-q(mid,{})&1){
            p3 = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    } 
    l = 1 , r = p3-1;
    while(l<=r){
        int mid = (l+r)/2;
        if((mid+1-q(mid,{p3}))&1){
            p2 = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    l = 1, r = p2-1;
    while(l<=r){
        int mid = (l+r)/2;
        if((mid+2-q(mid,{p2,p3}))&1){
            p1 = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << "! " << p1 << ' ' << p2 << ' ' << p3 << endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();    
}