#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<2*n;i++){
        int p1 = 2*n-i-1;
        int p2 = (i<n?3*n-i:n+i+1);
        int p3 = (i<n?i+(3*n+2):5*n-i+1);
        
        for(int j=0;j<4*n+2;j++){
            if(j==p1||j==p2||j==p3){
                cout << '*';
            }
            else cout << ' ';
        }
        cout << '\n';
    }
}