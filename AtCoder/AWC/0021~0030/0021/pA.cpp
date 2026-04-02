#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,k;
    cin>>n>>k;
    ll ans=0;
    while(n--){
        int a;
        cin>>a;
        for(int i=0;i<a;i++){
            int num;
            cin>>num;
            if(num>=k) ans++;
        }
    }
    cout << ans;
}