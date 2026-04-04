#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int m,d;
    cin>>m>>d;
    if(m&1){
        if(m>9) {
            cout << "No";
            return 0;
        }
        if(m==1){
            if(d==7) cout << "Yes";
            else cout << "No";
        }
        else {
            if(m==d){
                cout << "Yes";
            }
            else cout << "No";
        }
    }   
    else{
        cout << "No";
    } 
}