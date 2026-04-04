#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int h,w;
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(i==0||j==0||i==h-1||j==w-1) cout << '#';
            else cout << '.';
        }
        cout << '\n';
    }
}