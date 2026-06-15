#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int a[100];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int target;
    cin>>target;
    int l=0,r=n-1;
    bool ans=0;
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid]<target){
            l = mid+1;
        }
        else if(a[mid]>target){
            r = mid-1;
        }
        else ans = 1;
    }
    cout << ans << '\n';
}
