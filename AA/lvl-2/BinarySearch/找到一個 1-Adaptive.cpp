#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n/2 +1;i++){
        cout << "? " << i << endl;
        int v;
        cin>>v;
        if(v){
            cout << "! " << i << endl;
        }
    }
}