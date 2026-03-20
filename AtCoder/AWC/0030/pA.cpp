#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        cout << a/m << ' ' << a%m << '\n';
    }
}