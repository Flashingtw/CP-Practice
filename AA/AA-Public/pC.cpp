#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1)*2;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    cout << fixed << setprecision(6);
    while(t--){
        int n;
        cin>>n;
        cout << to_string(pi*n) << '\n';
    }
}