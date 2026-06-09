#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ll l = 1,r=1e9,a=0;
    while(l<=r){
        ll mid = l+(r-l)/2;
        cout << "? " << mid << endl;
        string ans;
        cin>>ans;
        if(ans=="NO"){
            a = mid;
            r = mid-1;
        }
        else l = mid+1; 
    }
    cout << "! " << a << endl;
}