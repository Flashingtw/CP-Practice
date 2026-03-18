#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s;
    cin>>s;
    int ptr=0;
    int n = s.size();
    int q;
    cin>>q;
    while(q--){
        char type;
        int x;
        cin>>type>>x;
        if(type=='M'){
            if(x>0){
                ptr = (ptr+x)%n;
            }
            else{
                ptr = (ptr+x+n)%n;
            }
        }
        else{
            x--;
            cout << s[(ptr+x)%n] << '\n';
        }
    }
}