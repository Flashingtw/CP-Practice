#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int x;
    cin>>x;
    string s;
    if(x==0) s.push_back('0');
    while(x){
        int n = x%3;
        if(n==2){
            s.push_back('O');
        }
        else if(n==1){
            s.push_back('o');
        }
        else s.push_back('0');
        x/=3;
        if(x!=0){
            s.push_back('.');
        }
    }
    for(char c:s) cout << c;
    cout << '\n';
}