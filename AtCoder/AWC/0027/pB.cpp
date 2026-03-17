#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    int mx=0,idx;
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        if(num>mx){
            mx = num;
            idx = i;
        }
    }
    if(idx==1) cout << -1;
    else cout << idx;
}