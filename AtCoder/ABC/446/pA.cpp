#include <bits/stdc++.h>
using namespace std;
int main(){
    string n;
    cin>>n;
    cout << "Of"; 
     for (char &c : n) {
        c = std::tolower(c);
    }
    cout << n;
}