#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(){
    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if(num>=k) ans++;
    }
    cout << ans;
}