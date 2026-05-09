#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v[i].resize(a);
        for(int j=0;j<a;j++){
            cin>>v[i][j];
        }
    }
    int x,y;
    cin>>x>>y;
    cout << v[x-1][y-1] << '\n';
}