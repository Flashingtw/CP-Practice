#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if(num<x){
            cout << 1 << '\n';
            x = num;
        }
        else cout << 0 << '\n';
    }
}