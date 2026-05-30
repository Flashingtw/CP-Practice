#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    int cnt=0;
    while(m!=0){
        int x = n%m;
        m = x;
        cnt++;
    }
    cout << cnt << '\n';
}