#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int l,m2,m3;
    cin>>l>>m2>>m3;
    for(int i=l;i<l+6;i++){
        if(i%2==m2&&i%3==m3){
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1;
}