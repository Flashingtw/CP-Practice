#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    int mx=0,smx=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a>mx){
            smx=mx;
            mx=a;
        }
        else if (a>smx){
            smx=a;
        }
    }
    cout << mx+smx;
}