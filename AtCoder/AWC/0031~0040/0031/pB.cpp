#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,t,ans=0;
    cin>>n>>t;
    for(int i=0;i<t;i++){
        int mx=0,sc=0;
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            if(a>mx){
                sc=mx;
                mx=a;
            }
            else if (a>sc){
                sc=a;
            }
        }
        if(mx>=2*sc) ans++;
    }
    cout << ans;
}