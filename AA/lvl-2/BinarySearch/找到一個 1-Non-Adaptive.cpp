#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1,n);
    for(int i=0;i<40;i++){
        int idx = dis(gen);
        cout << "? " << idx << endl;
        int ans;
        cin>>ans;
        if(ans){
            cout << "! " << idx << endl;
            break;
        }
    }
}