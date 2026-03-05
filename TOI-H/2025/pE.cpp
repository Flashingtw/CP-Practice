#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dist1[5005]; 

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin>>n;
    ll total = 0;
    for(int i = 1; i <= n; i++){
        ll mx = 0;
        for(int j = 1; j <= n; j++){
            ll d;
            cin >> d;
            if(i == 1) {
                dist1[j] = d;
            } 
            else if(j < i) {
                mx = max(mx, (dist1[j]+dist1[i]-d));
            }
        }
        if(i > 1) {
            total += 2*dist1[i] - mx;
        }
    }
    cout << total;
}