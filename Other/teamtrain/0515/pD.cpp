#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    int a=0,org = n;
    while(n>=10){
        a++;
        n/=10;
    }
    int num=0;
    for(int i=0;i<=a;i++){
        num*=10;
        num+=n;
    }
    int ans = a*10+n;
    cout << (num>org?ans-1:ans) << '\n';
}