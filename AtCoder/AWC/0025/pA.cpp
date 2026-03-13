#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,x;
    cin>>n>>x;
    int cnt=0;
    for(int i=0;i<n;i++) {
        int val;
        cin>>val;
        if(val<x) cnt++;
    }
    cout << cnt;
}