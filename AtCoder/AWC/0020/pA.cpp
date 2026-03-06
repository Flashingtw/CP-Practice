#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    ll sum=0;
    for(int i=0;i<n;i++) {
        int num;
        cin>>num;
        sum+=num;
    }
    cout << (sum%n==0?"Yes":"No");
}