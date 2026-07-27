#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    string a,b;
    cin>>a>>b;
    int n = a.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << a.substr(0,i) << b.substr(j,n);
            cout << '\n';
            cout << b.substr(0,i) << a.substr(j,n);
            cout << '\n' << '\n';
        }
    }
}