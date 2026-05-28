#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s;
    while(cin>>s){
        int sum=0;
        for(auto c:s){
            if(c!='/') sum+=c-'0';
        }
        int ans = (sum-1)%9 +1;
        string out;
        switch(ans){
            case 1:
                out = "Pioneer";
                break;
            case 2:
                out = "Collaborator";
                break;
            case 3:
                out = "Expresser";
                break;
            case 4:
                out = "Stable";
                break;
            case 5:
                out = "Free_Spirit";
                break;
            case 6:
                out = "Dedicated";
                break;
            case 7:
                out = "Seeker";
                break;
            case 8:
                out = "Practitioner";
                break;
            case 9:
                out = "Dreamer";
                break;
        }
        cout << out << '\n';
    }
}