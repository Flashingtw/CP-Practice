#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 1e6+5;
int a[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    for(int i=1;i<=1e6;i++){
        for(int j=i;j<=1e6;j+=i){
            a[j]++;
        }
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        cout << a[num] << '\n';
    }
}